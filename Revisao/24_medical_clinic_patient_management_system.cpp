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

    // Método para enfileirar um paciente na fila
    void enqueue(const std::string& paciente) {
        Node* newNode = new Node(paciente); // Cria um novo nó com o paciente fornecido

        if (isEmpty()) {
            front = rear = newNode; // Se a fila estiver vazia, o novo nó será o primeiro e o último
        } else {
            rear->next = newNode;   // Se a fila não estiver vazia, adiciona o novo nó após o último nó atual
            rear = newNode;         // Atualiza o ponteiro rear para o novo último nó
        }
    }

    // Método para desenfileirar um paciente da fila
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return;
        }

        Node* temp = front;     // Salva o ponteiro para o nó a ser removido
        front = front->next;    // Atualiza o ponteiro front para o próximo nó na fila
        delete temp;            // Libera a memória do nó removido
    }

    // Método para obter o paciente na frente da fila
    std::string getFront() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return ""; // Retorna uma string vazia para indicar erro
        }
        return front->data; // Retorna o paciente armazenado no nó da frente da fila
    }
};

// Definição da classe da pilha encadeada
class LinkedStack {
private:
    Node* top;  // Ponteiro para o topo da pilha

public:
    // Construtor para inicializar a pilha como vazia
    LinkedStack() : top(nullptr) {}

    // Destrutor para liberar a memória alocada para os nós da pilha
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();  // Desempilha todos os elementos restantes na pilha
        }
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() {
        return top == nullptr;
    }

    // Método para empilhar um paciente na pilha
    void push(const std::string& paciente) {
        Node* newNode = new Node(paciente, top); // Cria um novo nó com o paciente fornecido

        top = newNode; // Atualiza o ponteiro top para o novo nó
    }

    // Método para desempilhar um paciente da pilha
    void pop() {
        if (isEmpty()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return;
        }

        Node* temp = top;   // Salva o ponteiro para o nó no topo da pilha
        top = top->next;    // Atualiza o ponteiro top para o próximo nó na pilha
        delete temp;        // Libera a memória do nó removido
    }

    // Método para obter o paciente no topo da pilha
    std::string getTop() {
        if (isEmpty()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return ""; // Retorna uma string vazia para indicar erro
        }
        return top->data; // Retorna o paciente armazenado no nó do topo da pilha
    }
};

int main() {
    LinkedQueue filaRecepcao;   // Fila de pacientes na recepção
    LinkedStack pilhaConsulta;  // Pilha de pacientes na consulta do médico

    // Pacientes chegam e se registram na recepção
    filaRecepcao.enqueue("Paciente 1");
    filaRecepcao.enqueue("Paciente 2");
    filaRecepcao.enqueue("Paciente 3");
    filaRecepcao.enqueue("Paciente 4");

    // Pacientes são chamados para a consulta e entram na pilha do médico
    while (!filaRecepcao.isEmpty()) {
        pilhaConsulta.push(filaRecepcao.getFront()); // Adiciona o próximo paciente da fila à pilha de consulta
        filaRecepcao.dequeue(); // Remove o paciente da fila de recepção após ser chamado
    }

    // O médico atende os pacientes na ordem inversa em que foram chamados
    std::cout << "Pacientes sendo atendidos na consulta do médico:" << std::endl;
    while (!pilhaConsulta.isEmpty()) {
        std::cout << pilhaConsulta.getTop() << std::endl; // Exibe o paciente no topo da pilha de consulta
        pilhaConsulta.pop(); // Remove o paciente após ser atendido
    }

    return 0;
}
