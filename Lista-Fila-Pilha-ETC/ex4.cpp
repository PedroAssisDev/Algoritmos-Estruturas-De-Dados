#include <iostream>
#include <string>
#include <cctype> // Para a função tolower

// Definição do struct Nó
struct No {
    char caractere;
    No* proximo;
};

// Definição da classe da fila encadeada
class FilaEncadeada {
private:
    No* frente;
    No* tras;

public:
    // Construtor para inicializar a fila como vazia
    FilaEncadeada() : frente(nullptr), tras(nullptr) {}

    // Método para verificar se a fila está vazia
    bool estaVazia() {
        return frente == nullptr;
    }

    // Método para enfileirar um caractere na fila
    void enfileirar(char ch) {
        No* novo = new No;
        novo->caractere = ch;
        novo->proximo = nullptr;

        if (estaVazia()) {
            frente = tras = novo;
        } else {
            tras->proximo = novo;
            tras = novo;
        }
    }

    // Método para desenfileirar um caractere da fila
    char desenfileirar() {
        if (estaVazia()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return '\0';
        }

        No* temp = frente;
        char ch = frente->caractere;
        frente = frente->proximo;
        delete temp;
        return ch;
    }

    // Método para obter o caractere na frente da fila
    char obterFrente() {
        if (estaVazia()) {
            std::cout << "Erro: Fila vazia!" << std::endl;
            return '\0';
        }
        return frente->caractere;
    }
};

// Definição da classe da pilha
class PilhaEncadeada {
private:
    No* topo;

public:
    // Construtor para inicializar a pilha como vazia
    PilhaEncadeada() : topo(nullptr) {}

    // Método para verificar se a pilha está vazia
    bool estaVazia() {
        return topo == nullptr;
    }

    // Método para empilhar um caractere na pilha
    void empilhar(char ch) {
        No* novo = new No;
        novo->caractere = ch;
        novo->proximo = topo;
        topo = novo;
    }

    // Método para desempilhar um caractere da pilha
    char desempilhar() {
        if (estaVazia()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return '\0';
        }

        No* temp = topo;
        char ch = topo->caractere;
        topo = topo->proximo;
        delete temp;
        return ch;
    }

    // Método para obter o caractere no topo da pilha
    char obterTopo() {
        if (estaVazia()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return '\0';
        }
        return topo->caractere;
    }
};

// Função para verificar se uma sequência de string é um palíndromo
bool ehPalindromo(const std::string& str) {
    FilaEncadeada fila;
    PilhaEncadeada pilha;

    for (char ch : str) {
        if (isalpha(ch)) {
            fila.enfileirar(tolower(ch));
            pilha.empilhar(tolower(ch));
        }
    }

    while (!fila.estaVazia() && !pilha.estaVazia()) {
        if (fila.obterFrente() != pilha.obterTopo()) {
            return false;
        }
        fila.desenfileirar();
        pilha.desempilhar();
    }

    return fila.estaVazia() && pilha.estaVazia();
}

int main() {
    std::string str;
    std::cout << "Digite uma sequência de caracteres para verificar se é um palíndromo: ";
    std::getline(std::cin, str);

    if (ehPalindromo(str)) {
        std::cout << "A sequência \"" << str << "\" é um palíndromo." << std::endl;
    } else {
        std::cout << "A sequência \"" << str << "\" não é um palíndromo." << std::endl;
    }

    return 0;
}
