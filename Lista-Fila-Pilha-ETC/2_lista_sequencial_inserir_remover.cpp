#include <iostream>

struct Elemento {
    int chave;
};

// Função de busca sequencial na lista de elementos
int busca(Elemento L[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (L[i].chave == x) {
            return i + 1; // Elemento encontrado na posição i
        }
    }
    return 0; // Elemento não encontrado
}

// Procedimento de inserção de um nó na lista L
void insercao(Elemento L[], int& n, int M, int x) {
    if (n < M) {
        if (busca(L, n, x) == 0) {
            L[n].chave = x;
            n++;
        } else {
            std::cout << "Elemento já existe na tabela." << std::endl;
        }
    } else {
        std::cout << "Overflow." << std::endl;
    }
}

// Procedimento de remoção de um nó da lista L
void remocao(Elemento L[], int& n, int x) {
    if (n != 0) {
        int indice = busca(L, n, x);
        if (indice != 0) {
            for (int i = indice - 1; i < n - 1; i++) {
                L[i] = L[i + 1];
            }
            n--;
        } else {
            std::cout << "Elemento não se encontra na tabela." << std::endl;
        }
    } else {
        std::cout << "Underflow." << std::endl;
    }
}

int main() {
    const int M = 5; // Tamanho máximo da lista
    Elemento lista[M + 1]; // Tabela com uma posição extra para a sentinela
    int n = 0; // Número atual de elementos na lista

    // Exemplo de inserção e remoção
    insercao(lista, n, M, 10);
    insercao(lista, n, M, 20);
    insercao(lista, n, M, 30);
    insercao(lista, n, M, 40);
    insercao(lista, n, M, 50);
    insercao(lista, n, M, 90);

    remocao(lista, n, 30);
    remocao(lista, n, 15); // Tentativa de remover elemento que não existe

    return 0;
}
