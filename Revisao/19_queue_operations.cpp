#include <iostream>

// Define o tamanho máximo da fila
#define MAX_SIZE 5

// Definição da classe Fila
class Queue {
private:
    int front, rear, size; // Índices front, rear e tamanho da fila
    int array[MAX_SIZE];   // Array para armazenar os elementos da fila

public:
    // Construtor da classe Fila
    Queue() {
        front = rear = -1; // Inicializa os índices front e rear como -1
        size = 0;           // Inicializa o tamanho da fila como 0
    }

    // Método para verificar se a fila está vazia
    bool isEmpty() {
        return size == 0; // Retorna verdadeiro se o tamanho da fila for 0
    }

    // Método para verificar se a fila está cheia
    bool isFull() {
        return size == MAX_SIZE; // Retorna verdadeiro se o tamanho da fila for igual ao tamanho máximo definido
    }

    // Método para enfileirar um elemento na fila
    void enqueue(int item) {
        if (isFull()) { // Verifica se a fila está cheia
            std::cout << "Erro: Fila cheia!" << std::endl; // Imprime uma mensagem de erro
            return; // Retorna sem fazer nada
        }
        if (isEmpty()) { // Verifica se a fila está vazia
            front = rear = 0; // Se estiver vazia, define front e rear como 0
        } else {
            rear = (rear + 1) % MAX_SIZE; // Atualiza o índice rear circularmente
        }
        array[rear] = item; // Insere o elemento na posição rear do array
        size++; // Incrementa o tamanho da fila
        std::cout << "Elemento " << item << " enfileirado com sucesso!" << std::endl; // Imprime uma mensagem de sucesso
    }

    // Método para desenfileirar um elemento da fila
    void dequeue() {
        if (isEmpty()) { // Verifica se a fila está vazia
            std::cout << "Erro: Fila vazia!" << std::endl; // Imprime uma mensagem de erro
            return; // Retorna sem fazer nada
        }
        int removed = array[front]; // Armazena o elemento a ser removido
        if (front == rear) { // Verifica se a fila possui apenas um elemento
            front = rear = -1; // Se sim, define front e rear como -1
        } else {
            front = (front + 1) % MAX_SIZE; // Atualiza o índice front circularmente
        }
        size--; // Decrementa o tamanho da fila
        std::cout << "Elemento " << removed << " desenfileirado com sucesso!" << std::endl; // Imprime uma mensagem de sucesso
    }

    // Método para obter o elemento na frente da fila
    int getFront() {
        if (isEmpty()) { // Verifica se a fila está vazia
            std::cout << "Erro: Fila vazia!" << std::endl; // Imprime uma mensagem de erro
            return -1; // Retorna um valor sentinela indicando erro
        }
        return array[front]; // Retorna o elemento na posição front do array
    }

    // Método para obter o tamanho atual da fila
    int getSize() {
        return size; // Retorna o tamanho da fila
    }
};

// Função principal
int main() {
    Queue fila; // Cria um objeto da classe Fila

    // Verifica se a fila está vazia
    std::cout << "A fila está vazia? " << (fila.isEmpty() ? "Sim" : "Não") << std::endl;

    // Enfileira elementos na fila
    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);
    fila.enqueue(40);
    fila.enqueue(50);


    // Obtém o tamanho atual da fila
    std::cout << "Tamanho da fila: " << fila.getSize() << std::endl;

    // Obtém o elemento na frente da fila
    std::cout << "Elemento na frente da fila: " << fila.getFront() << std::endl;

    // Desenfileira um elemento da fila
    fila.dequeue();
    // Obtém o elemento na frente da fila
    std::cout << "Elemento na frente da fila: " << fila.getFront() << std::endl;
    fila.enqueue(60);
    // Obtém o elemento na frente da fila
    std::cout << "Elemento na frente da fila: " << fila.getFront() << std::endl;

    // Obtém o tamanho atual da fila após a desenfileiração
    std::cout << "Tamanho da fila após desenfileirar: " << fila.getSize() << std::endl;

    return 0;
}
