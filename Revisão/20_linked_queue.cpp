#include <iostream>

// Definição da estrutura do nó da fila
struct Node {
    int data;       // Dado armazenado no nó
    Node* next;     // Ponteiro para o próximo nó na fila

    // Construtor para inicializar um nó com dado e próximo nó fornecidos
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};

// Definição da classe da fila encadeada
class LinkedQueue {
private:
    Node* front;    // Ponteiro para o primeiro nó da fila
    Node* rear;     // Ponteiro para o último nó da fila

public:
    // Construtor para inicializar a fila como vazia
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    // Destrutor para liberar a memória alocada para os nós da fila
    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();  // Desenfileira todos os elementos restantes na fila
        }
    }

    // Método para verificar se a fila está vazia
    bool isEmpty() {
        return front == nullptr;
    }

    // Método para enfileirar um elemento na fila
    void enqueue(int val) {
        Node* newNode = new Node(val); // Cria um novo nó com o valor fornecido

        if (isEmpty()) {
            front = rear = newNode; // Se a fila estiver vazia, o novo nó será o primeiro e o último
        } else {
            rear->next = newNode;   // Se a fila não estiver vazia, adiciona o novo nó após o último nó atual
            rear = newNode;         // Atualiza o ponteiro rear para o novo último nó
        }
    }

    // Método para desenfileirar um elemento da fila
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return;
        }

        Node* temp = front;     // Salva o ponteiro para o nó a ser removido
        front = front->next;    // Atualiza o ponteiro front para o próximo nó na fila
        delete temp;            // Libera a memória do nó removido
    }

    // Método para obter o elemento na frente da fila
    int getFront() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return -1; // Valor sentinela indicando erro
        }
        return front->data; // Retorna o dado armazenado no nó da frente da fila
    }

    // Método para exibir os elementos da fila
    void display() {
        if (isEmpty()) {
            std::cout << "Fila vazia!" << std::endl;
            return;
        }

        std::cout << "Elementos da fila: ";
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedQueue queue;

    // Verificando se a fila está vazia
    std::cout << "A fila está vazia? " << (queue.isEmpty() ? "Sim" : "Não") << std::endl;

    // Enfileirando elementos e exibindo a fila após cada operação
    std::cout << "\nEnfileirando elementos:" << std::endl;
    queue.enqueue(10);
    queue.display();
    queue.enqueue(20);
    queue.display();
    queue.enqueue(30);
    queue.display();

    // Exibindo os elementos da fila
    std::cout << "\nElementos da fila:" << std::endl;
    queue.display();

    // Desenfileirando um elemento e exibindo a fila após a operação
    std::cout << "\nDesenfileirando um elemento:" << std::endl;
    queue.dequeue();
    queue.display();

    return 0;
}
