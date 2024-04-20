#include <iostream>

// Definição da estrutura do nó da pilha
struct Node {
    int data; // Valor do nó
    Node* next; // Ponteiro para o próximo nó
};

// Classe para representar uma pilha utilizando lista encadeada
class LinkedStack {
private:
    Node* top; // Ponteiro para o topo da pilha

public:
    // Construtor da pilha
    LinkedStack(){
        top = NULL;
    }

    // Destrutor da pilha
    ~LinkedStack() {
        // Libera a memória alocada para cada nó da pilha
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() const {
        return top == nullptr;
    }

    // Método para empilhar um elemento na pilha
    void push(int value) {
        Node* newNode = new Node; // Cria um novo nó
        newNode->data = value; // Atribui o valor ao novo nó
        newNode->next = top; // Define o próximo nó como o atual topo
        top = newNode; // Atualiza o topo da pilha
        std::cout << "Elemento " << value << " empilhado com sucesso!" << std::endl;
    }

    // Método para desempilhar um elemento da pilha
    void pop() {
        if (isEmpty()) {
            std::cerr << "Erro: Pilha vazia!" << std::endl;
            return;
        }
        Node* temp = top; // Armazena o nó que será removido
        top = top->next; // Atualiza o topo da pilha
        int removed = temp->data; // Armazena o valor do nó removido
        delete temp; // Libera a memória do nó removido
        std::cout << "Elemento " << removed << " desempilhado com sucesso!" << std::endl;
    }

    // Método para obter o elemento no topo da pilha
    int getTop() const {
        if (isEmpty()) {
            std::cerr << "Erro: Pilha vazia!" << std::endl;
            return -1; // Valor sentinela indicando erro
        }
        return top->data; // Retorna o valor do nó no topo da pilha
    }

    // Método para exibir os elementos da pilha
    void display() const {
        if (isEmpty()) {
            std::cout << "Pilha vazia!" << std::endl;
            return;
        }
        std::cout << "Elementos da pilha:" << std::endl;
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedStack stack;

    // Empilhando elementos
    stack.display();
    stack.push(10);
    stack.display();
    stack.push(20);
    stack.display();
    stack.push(30);
    stack.display();

    // Exibindo os elementos da pilha
    stack.display();

    // Desempilhando um elemento
    stack.pop();

    // Exibindo os elementos da pilha após a desempilhação
    stack.display();

    return 0;
}
