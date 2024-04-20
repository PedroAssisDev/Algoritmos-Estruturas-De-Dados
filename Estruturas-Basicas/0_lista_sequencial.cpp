#include <iostream>

struct Elemento {
    char chave;
};

// Função de busca sequencial na lista
int buscaSequencial(Elemento L[], int n, char x) {
    int i = 0;
    while (i < n) {
        if (L[i].chave == x) {
            // Retorna o índice do elemento encontrado
            return i;
        }
        i++;
    }
    // Retorna -1 se o elemento não foi encontrado
    return -1;
}

// Função de busca com sentinela na lista
int buscaComSentinela(Elemento L[], int n, char x) {
    // Adiciona o elemento x na posição n+1 para criar uma "sentinela"
    L[n + 1].chave = x;
    int i = 0;
    // Enquanto a chave do elemento não for x, avança para o próximo elemento
    while (L[i].chave != x) {
        i++;
    }
    // Se i for diferente de n + 1, o elemento foi encontrado e retorna seu índice
    if (i != n + 1) {
        return i;
    } else {
        // Caso contrário, o elemento não foi encontrado e retorna -1
        return -1;
    }
}

int main() {
    const int tamanho = 5;
    Elemento lista[tamanho] = {'a', 'b', 'c', 'd', 'e'};
    char elementoBuscado = 'c';

    // Busca utilizando a função de busca sequencial
    int indiceSequencial = buscaSequencial(lista, tamanho, elementoBuscado);
    if (indiceSequencial != -1) {
        std::cout << "Busca Sequencial - Elemento encontrado na posição: " << indiceSequencial + 1 << std::endl;
    } else {
        std::cout << "Busca Sequencial - Elemento não encontrado na lista." << std::endl;
    }

    // Busca utilizando a função de busca com sentinela
    int indiceSentinela = buscaComSentinela(lista, tamanho, elementoBuscado);
    if (indiceSentinela != -1) {
        std::cout << "Busca com Sentinela - Elemento encontrado na posição: " << indiceSentinela + 1 << std::endl;
    } else {
        std::cout << "Busca com Sentinela - Elemento não encontrado na lista." << std::endl;
    }

    return 0;
}
