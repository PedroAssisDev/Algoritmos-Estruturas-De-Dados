#include <iostream>
#include <string>

// Definição da estrutura do nó da fila
struct Node {
    char data;      // Caractere armazenado no nó
    Node* next;     // Ponteiro para o próximo nó na fila

    // Construtor para inicializar um nó com caractere e próximo nó fornecidos
    Node(char ch, Node* nxt = nullptr) : data(ch), next(nxt) {}
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

    // Método para enfileirar um caractere na fila
    void enqueue(char ch) {
        Node* newNode = new Node(ch); // Cria um novo nó com o caractere fornecido

        if (isEmpty()) {
            front = rear = newNode; // Se a fila estiver vazia, o novo nó será o primeiro e o último
        } else {
            rear->next = newNode;   // Se a fila não estiver vazia, adiciona o novo nó após o último nó atual
            rear = newNode;         // Atualiza o ponteiro rear para o novo último nó
        }
    }

    // Método para desenfileirar um caractere da fila
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return;
        }

        Node* temp = front;     // Salva o ponteiro para o nó a ser removido
        front = front->next;    // Atualiza o ponteiro front para o próximo nó na fila
        delete temp;            // Libera a memória do nó removido
    }

    // Método para obter o caractere na frente da fila
    char getFront() {
        if (isEmpty()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return '\0'; // Valor sentinela indicando erro
        }
        return front->data; // Retorna o caractere armazenado no nó da frente da fila
    }
};

// Definição da classe da pilha
class Stack {
private:
    Node* top;      // Ponteiro para o topo da pilha

public:
    // Construtor para inicializar a pilha como vazia
    Stack() : top(nullptr) {}

    // Destrutor para liberar a memória alocada para os nós da pilha
    ~Stack() {
        while (!isEmpty()) {
            pop();  // Desempilha todos os elementos restantes na pilha
        }
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() {
        return top == nullptr;
    }

    // Método para empilhar um caractere na pilha
    void push(char ch) {
        Node* newNode = new Node(ch, top); // Cria um novo nó com o caractere fornecido e o ponteiro para o próximo nó sendo o antigo topo
        top = newNode; // Atualiza o ponteiro top para o novo nó
    }

    // Método para desempilhar um caractere da pilha
    void pop() {
        if (isEmpty()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return;
        }

        Node* temp = top;   // Salva o ponteiro para o nó a ser removido
        top = top->next;    // Atualiza o ponteiro top para o próximo nó na pilha
        delete temp;        // Libera a memória do nó removido
    }

    // Método para obter o caractere no topo da pilha
    char getTop() {
        if (isEmpty()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return '\0'; // Valor sentinela indicando erro
        }
        return top->data; // Retorna o caractere armazenado no topo da pilha
    }
};

// Função para verificar se uma sequência de string é um palíndromo
bool isPalindrome(const std::string& str) {
    LinkedQueue queue;  // Fila encadeada para armazenar os caracteres da string
    Stack stack;        // Pilha para armazenar os caracteres da string

    // Enfileira e empilha os caracteres da string
    for (char ch : str) {
        if (isalpha(ch)) {  // Verifica se o caractere é uma letra
            queue.enqueue(tolower(ch));    // Converte o caractere para minúscula e enfileira na fila
            stack.push(tolower(ch));        // Converte o caractere para minúscula e empilha na pilha
        }
    }

    // Desenfileira e desempilha os caracteres da string, verificando se são iguais
    while (!queue.isEmpty() && !stack.isEmpty()) {
        if (queue.getFront() != stack.getTop()) { // Compara o caractere da frente da fila com o caractere no topo da pilha
            return false; // Se forem diferentes, a string não é um palíndromo
        }
        queue.dequeue();    // Desenfileira o caractere da fila
        stack.pop();        // Desempilha o caractere da pilha
    }

    // Se a fila e a pilha estiverem vazias, significa que todos os caracteres foram iguais
    return queue.isEmpty() && stack.isEmpty();
}

int main() {
    std::string str;
    std::cout << "Digite uma sequência de caracteres para verificar se é um palíndromo: ";
    std::getline(std::cin, str);

    if (isPalindrome(str)) {
        std::cout << "A sequência \"" << str << "\" é um palíndromo." << std::endl;
    } else {
        std::cout << "A sequência \"" << str << "\" não é um palíndromo." << std::endl;
    }

    return 0;
}
