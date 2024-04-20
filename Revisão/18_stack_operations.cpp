#include <iostream>

// Define o tamanho máximo da pilha
#define MAX_SIZE 5

// Definição da classe Pilha
class Stack {
private:
    int top;        // Índice do topo da pilha
    int array[MAX_SIZE];   // Array para armazenar os elementos da pilha

public:
    // Construtor da classe Pilha
    Stack() {
        top = -1; // Inicializa o índice do topo como -1
    }

    // Destrutor da classe Pilha
    ~Stack() {
        // Não é necessário fazer nada, pois o array é um array estático
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() {
        return top == -1; // Retorna verdadeiro se o topo for igual a -1
    }

    // Método para verificar se a pilha está cheia
    bool isFull() {
        return top == MAX_SIZE - 1; // Retorna verdadeiro se o topo for igual ao tamanho máximo menos 1
    }

    // Método para empilhar um elemento na pilha
    void push(int item) {
        if (isFull()) { // Verifica se a pilha está cheia
            std::cout << "Erro: Pilha cheia!" << std::endl; // Imprime uma mensagem de erro
            return; // Retorna sem fazer nada
        }
        array[++top] = item; // Incrementa o topo e insere o elemento na posição correspondente do array
        std::cout << "Elemento " << item << " empilhado com sucesso!" << std::endl; // Imprime uma mensagem de sucesso
    }

    // Método para desempilhar um elemento da pilha
    void pop() {
        if (isEmpty()) { // Verifica se a pilha está vazia
            std::cout << "Erro: Pilha vazia!" << std::endl; // Imprime uma mensagem de erro
            return; // Retorna sem fazer nada
        }
        int removed = array[top--]; // Armazena o elemento a ser removido e decrementa o topo
        std::cout << "Elemento " << removed << " desempilhado com sucesso!" << std::endl; // Imprime uma mensagem de sucesso
    }

    // Método para obter o elemento no topo da pilha
    int getTop() {
        if (isEmpty()) { // Verifica se a pilha está vazia
            std::cout << "Erro: Pilha vazia!" << std::endl; // Imprime uma mensagem de erro
            return -1; // Retorna um valor sentinela indicando erro
        }
        return array[top]; // Retorna o elemento no topo da pilha
    }

    // Método para obter o tamanho atual da pilha
    int getSize() {
        return top + 1; // Retorna o tamanho da pilha
    }
};

// Função principal
int main() {
    Stack pilha; // Cria um objeto da classe Pilha

    // Verifica se a pilha está vazia
    std::cout << "A pilha está vazia? " << (pilha.isEmpty() ? "Sim" : "Não") << std::endl;

    // Empilha elementos na pilha
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);
    pilha.push(50);



    // Obtém o tamanho atual da pilha
    std::cout << "Tamanho da pilha: " << pilha.getSize() << std::endl;

    // Obtém o elemento no topo da pilha
    std::cout << "Elemento no topo da pilha: " << pilha.getTop() << std::endl;

    // Desempilha um elemento da pilha
    pilha.pop();
    pilha.push(60);

    // Obtém o tamanho atual da pilha após a desempilhação
    std::cout << "Tamanho da pilha após desempilhar: " << pilha.getSize() << std::endl;

    return 0;
}
