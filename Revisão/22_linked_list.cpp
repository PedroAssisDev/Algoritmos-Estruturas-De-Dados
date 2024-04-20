#include <iostream>

// Definição da estrutura do nó da lista encadeada
struct Node {
    int data; // Valor do nó
    Node* next; // Ponteiro para o próximo nó
};

// Classe para representar uma lista encadeada
class LinkedList {
private:
    Node* head; // Ponteiro para o primeiro nó da lista

public:
    // Construtor da lista encadeada
    LinkedList() : head(nullptr) {}

    // Destrutor da lista encadeada
    ~LinkedList() {
        // Libera a memória alocada para cada nó da lista
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Método para inserir um elemento no início da lista
    void insertAtBeginning(int value) {
        Node* newNode = new Node; // Cria um novo nó
        newNode->data = value; // Atribui o valor ao novo nó
        newNode->next = head; // Define o próximo nó como o atual primeiro nó
        head = newNode; // Atualiza o ponteiro para o primeiro nó
    }

    // Método para inserir um elemento no final da lista
    void insertAtEnd(int value) {
        Node* newNode = new Node; // Cria um novo nó
        newNode->data = value; // Atribui o valor ao novo nó
        newNode->next = nullptr; // Define o próximo nó como nulo (último nó)
        if (head == nullptr) { // Se a lista estiver vazia
            head = newNode; // O novo nó é o primeiro nó da lista
        } else {
            Node* current = head;
            // Percorre a lista até encontrar o último nó
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode; // Define o próximo nó do último nó como o novo nó
        }
    }

    // Método para inserir um elemento em uma posição específica da lista
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            std::cerr << "Erro: Posição inválida!" << std::endl;
            return;
        }
        Node* newNode = new Node; // Cria um novo nó
        newNode->data = value; // Atribui o valor ao novo nó
        if (position == 0) { // Se a posição for 0, insere no início
            newNode->next = head; // Define o próximo nó como o atual primeiro nó
            head = newNode; // Atualiza o ponteiro para o primeiro nó
            return;
        }
        Node* current = head;
        // Percorre a lista até a posição anterior à posição de inserção
        for (int i = 0; i < position - 1; ++i) {
            if (current == nullptr) {
                std::cerr << "Erro: Posição inválida!" << std::endl;
                return;
            }
            current = current->next;
        }
        newNode->next = current->next; // Define o próximo nó do novo nó como o próximo nó do nó atual
        current->next = newNode; // Define o próximo nó do nó atual como o novo nó
    }

    // Método para remover o primeiro elemento da lista
    void removeFirst() {
        if (head == nullptr) { // Se a lista estiver vazia
            std::cerr << "Erro: Lista vazia!" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next; // Atualiza o ponteiro para o primeiro nó
        delete temp; // Libera a memória do nó removido
    }

    // Método para remover o último elemento da lista
    void removeLast() {
        if (head == nullptr) { // Se a lista estiver vazia
            std::cerr << "Erro: Lista vazia!" << std::endl;
            return;
        }
        if (head->next == nullptr) { // Se houver apenas um nó na lista
            delete head; // Libera a memória do único nó
            head = nullptr; // Define o ponteiro para o primeiro nó como nulo
            return;
        }
        Node* current = head;
        // Percorre a lista até o penúltimo nó
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next; // Libera a memória do último nó
        current->next = nullptr; // Define o próximo nó do penúltimo nó como nulo
    }

    // Método para remover um elemento em uma posição específica da lista
    void removeAtPosition(int position) {
        if (position < 0) {
            std::cerr << "Erro: Posição inválida!" << std::endl;
            return;
        }
        if (position == 0) { // Se a posição for 0, remove o primeiro elemento
            removeFirst();
            return;
        }
        Node* current = head;
        // Percorre a lista até o nó anterior ao nó que será removido
        for (int i = 0; i < position - 1; ++i) {
            if (current == nullptr || current->next == nullptr) {
                std::cerr << "Erro: Posição inválida!" << std::endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next; // Armazena o nó que será removido
        current->next = current->next->next; // Atualiza o próximo nó do nó anterior
        delete temp; // Libera a memória do nó removido
    }

    // Método para imprimir os elementos da lista
    void display() {
        Node* current = head;
        std::cout << "Lista: "; 
        while (current != nullptr) {
            std::cout << current->data << " "; // Imprime o valor do nó
            current = current->next; // Move para o próximo nó
        }
        std::cout << std::endl;
    }

    // Método para verificar se a lista está vazia
    bool isEmpty() {
        return head == nullptr;
    }

    // Método para obter o tamanho da lista
    int getSize() {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            ++size; // Incrementa o tamanho
            current = current->next; // Move para o próximo nó
        }
        return size;
    }
};

int main() {
    LinkedList list;

    // Inserindo elementos na lista
    list.display();
    list.insertAtEnd(10);
    list.display();
    list.insertAtEnd(20);
    list.display();
    list.insertAtBeginning(5);
    list.display();
    list.insertAtPosition(15, 2);
    list.display();

    // Exibindo os elementos da lista
    std::cout << "Lista encadeada: ";
    list.display();

    // Removendo elementos da lista
    list.removeFirst();
    list.display();
    list.removeLast();
    list.display();
    list.removeAtPosition(1);
    list.display();

    // Exibindo os elementos da lista após remoção
    std::cout << "Lista após remoção: ";
    list.display();

    // Verificando o tamanho da lista
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;

    // Verificando se a lista está vazia
    std::cout << "A lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;

    return 0;
}
