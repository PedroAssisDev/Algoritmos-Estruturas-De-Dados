#include <iostream>
#include <string>

// Definição da estrutura do nó da fila
struct Node {
    std::string data;   // Dados armazenados no nó
    Node* next;         // Ponteiro para o próximo nó na fila

    // Construtor para inicializar um nó com dados e próximo nó fornecidos
    Node(const std::string& d, Node* nxt = nullptr) : data(d), next(nxt) {}
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

    // Método para enfileirar um cliente na fila
    void enqueue(const std::string& cliente) {
        Node* newNode = new Node(cliente); // Cria um novo nó com o cliente fornecido

        if (isEmpty()) {
            front = rear = newNode; // Se a fila estiver vazia, o novo nó será o primeiro e o último
        } else {
            rear->next = newNode;   // Se a fila não estiver vazia, adiciona o novo nó após o último nó atual
            rear = newNode;         // Atualiza o ponteiro rear para o novo último nó
        }
    }

    // Método para desenfileirar um cliente da fila
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return;
        }

        Node* temp = front;     // Salva o ponteiro para o nó a ser removido
        front = front->next;    // Atualiza o ponteiro front para o próximo nó na fila
        delete temp;            // Libera a memória do nó removido
    }

    // Método para obter o cliente na frente da fila
    std::string getFront() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return ""; // Retorna uma string vazia para indicar erro
        }
        return front->data; // Retorna o cliente armazenado no nó da frente da fila
    }
};

int main() {
    LinkedQueue filaBanco; // Cria uma fila para representar a fila de atendimento no banco

    // Clientes chegam e são adicionados à fila
    filaBanco.enqueue("Cliente 1");
    filaBanco.enqueue("Cliente 2");
    filaBanco.enqueue("Cliente 3");
    filaBanco.enqueue("Cliente 4");

    while (~filaBanco.isEmpty())
    {
         // Exibe o próximo cliente a ser atendido
        std::cout << "Próximo cliente a ser atendido: " << filaBanco.getFront() << std::endl;
        // O próximo cliente é atendido e removido da fila
        filaBanco.dequeue();
    }

    return 0;
}
