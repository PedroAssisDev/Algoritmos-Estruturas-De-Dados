#include <iostream>

struct Elemento {
    int chave;
};

// Função de busca ordenada sequencial na lista de elementos
int buscaOrdenada(Elemento L[], int n, Elemento x) {
    L[n] = x; // Adiciona o elemento x na posição n para criar uma "sentinela"
    int i = 0;
    while (L[i].chave < x.chave) {
        i++;
    }
    if (i == n || L[i].chave != x.chave) {
        return 0; // Elemento não encontrado
    } else {
        return i; // Elemento encontrado na posição i
    }
}

// Função de busca binária na lista de elementos
int buscaBinaria(Elemento L[], int n, Elemento x) {
    int inf = 0, sup = n - 1;
    while (inf <= sup) {
        int meio = (inf + sup) / 2;
        if (L[meio].chave == x.chave) {
            return meio; // Elemento encontrado na posição meio
        } else if (L[meio].chave < x.chave) {
            inf = meio + 1;
        } else {
            sup = meio - 1;
        }
    }
    return 0; // Elemento não encontrado
}

int main() {
    const int tamanho = 5;
    Elemento lista[tamanho] = {1, 3, 5, 7, 9};
    Elemento elementoBuscado = {7};

    // Busca ordenada sequencial
    int indiceOrdenada = buscaOrdenada(lista, tamanho, elementoBuscado);
    if (indiceOrdenada != 0) {
        std::cout << "Busca Ordenada Sequencial - Elemento encontrado na posição: " << indiceOrdenada + 1 << std::endl;
    } else {
        std::cout << "Busca Ordenada Sequencial - Elemento não encontrado na lista." << std::endl;
    }

    // Busca binária
    int indiceBinaria = buscaBinaria(lista, tamanho, elementoBuscado);
    if (indiceBinaria != 0) {
        std::cout << "Busca Binária - Elemento encontrado na posição: " << indiceBinaria + 1 << std::endl;
    } else {
        std::cout << "Busca Binária - Elemento não encontrado na lista." << std::endl;
    }

    return 0;
}
