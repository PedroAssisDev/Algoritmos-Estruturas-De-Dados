#include <iostream>

using namespace std;

// Definição do struct No
struct No {
    int valor;
    No* proximo;
};

// Definição da Fila com Lista Simplesmente Encadeada
struct Fila {
    No* head;
    No* tail;
};

// Função para inserir um valor no final da fila
void inserir(int k, Fila* L) {
    No* novo = new No;
    novo->valor = k;
    novo->proximo = nullptr;

    // Se a fila estiver vazia, o novo nó será tanto o início quanto o fim da fila
    if (L->head == nullptr) {
        L->head = novo;
    } else {
        // Caso contrário, o novo nó será inserido após o último nó
        L->tail->proximo = novo;
    }

    L->tail = novo;
}

// Função para remover o primeiro valor da fila
void remover(Fila* L) {
    // Se a fila estiver vazia, não há nada para remover
    if (L->head == nullptr) {
        cout << "Fila vazia. Não há elementos para remover." << endl;
        return;
    }

    No* primeiro = L->head;
    L->head = primeiro->proximo;

    // Se a fila agora estiver vazia, atualizamos a cauda também
    if (L->head == nullptr) {
        L->tail = nullptr;
    }

    delete primeiro;
}

int main() {
    // Inicializa a fila
    Fila fila;
    fila.head = nullptr;
    fila.tail = nullptr;

    // Insere alguns valores na fila
    inserir(5, &fila);
    inserir(10, &fila);
    inserir(15, &fila);

    // Remove o primeiro elemento da fila
    remover(&fila);

    return 0;
}
