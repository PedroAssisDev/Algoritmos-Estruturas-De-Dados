#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h> // Para semáforos

// Definindo o número total de threads
const int numThreads = 5;

// Variável global compartilhada entre as threads
int recursoCompartilhado = 0;

// Mutex para sincronização durante a impressão
std::mutex mtx;

// Semáforos para controlar o acesso à seção crítica e à impressão
sem_t semaforoAcesso, semaforoImpressao;


// Função que será executada por cada thread
void funcaoThread(int id) {
    // Simula alguma operação antes de acessar a seção crítica
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Bloqueia o semáforo de acesso à seção crítica
    sem_wait(&semaforoAcesso);

    // Seção crítica - acessa e atualiza o recurso compartilhado
    recursoCompartilhado++;
    {
        std::lock_guard<std::mutex> guard(mtx);
        printf("Thread %d atualizou o recurso compartilhado para: %d\n", id, recursoCompartilhado);
    }

    // Libera o semáforo de acesso à seção crítica
    sem_post(&semaforoAcesso);

    // Libera o semáforo de impressão para permitir que outra thread imprima
    sem_post(&semaforoImpressao);
}

int main() {
    // Inicializa os semáforos com os valores iniciais
    sem_init(&semaforoAcesso, 0, 1); // Semáforo de acesso à seção crítica (inicializado com 1 para permitir o acesso inicial)
    sem_init(&semaforoImpressao, 0, 1); // Semáforo de impressão (inicializado com 1 para permitir a impressão inicial)

    // Array para armazenar as threads
    std::thread threads[numThreads];

    // Inicia as threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(funcaoThread, i);
    }

    // Espera todas as threads terminarem
    for (int i = 0; i < numThreads; ++i) {
        // Bloqueia o semáforo de impressão para garantir a sincronização da impressão
        sem_wait(&semaforoImpressao);

        threads[i].join();
    }

    // Destroi os semáforos após o uso
    sem_destroy(&semaforoAcesso);
    sem_destroy(&semaforoImpressao);

    return 0;
}
