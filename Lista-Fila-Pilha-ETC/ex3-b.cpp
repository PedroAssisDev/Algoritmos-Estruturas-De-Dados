#include <iostream>
#include <cmath>
using namespace std;

// Definição do struct Nó
struct No {
    int valor;
    No* proximo;
};

// Função para inserir um valor no final de uma lista encadeada
void inserirFinal(int valor, No*& lista) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = nullptr;

    if (lista == nullptr) {
        lista = novo;
    } else {
        No* atual = lista;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Função para calcular o tamanho de uma lista encadeada
int tamanhoLista(No* lista) {
    int tamanho = 0;
    while (lista != nullptr) {
        tamanho++;
        lista = lista->proximo;
    }
    return tamanho;
}

// Função para construir L'' conforme especificado
No* construirListaIntermediaria(No* L) {
    // Calcula o tamanho da lista L
    int tamanho = tamanhoLista(L);

    // Determina o índice do último nó da primeira metade da lista L
    int indice_ultimo_primeira_metade = tamanho / 2;

    // Percorre a lista L para calcular as somas e construir L''
    No* L_intermediaria = nullptr;
    No* atual = L;
    for (int i = 1; i <= indice_ultimo_primeira_metade; i++) {
        // Encontra o nó correspondente no final da lista
        No* no_final = atual;
        for (int j = 1; j < tamanho - i + 1; j++) {
            no_final = no_final->proximo;
        }

        // Calcula a soma dos valores dos nós
        int soma = atual->valor + no_final->valor;

        // Insere a soma na lista intermediária
        inserirFinal(soma, L_intermediaria);

        // Move para o próximo nó em L
        atual = atual->proximo;
    }

    return L_intermediaria;
}

// Função para imprimir os elementos de uma lista encadeada
void imprimirLista(No* lista) {
    while (lista != nullptr) {
        cout << lista->valor << " ";
        lista = lista->proximo;
    }
    cout << endl;
}

int main() {
    // Exemplo de uma lista encadeada L
    No* L = nullptr;

    // Inserindo alguns valores em L
    for (int i = 1; i <= 8; i++) {
        inserirFinal(i, L);
    }

    // Construindo a lista intermediária L''
    No* L_intermediaria = construirListaIntermediaria(L);

    // Imprimindo L'' para verificar se está correto
    cout << "Lista intermediária L'':" << endl;
    imprimirLista(L_intermediaria);

    return 0;
}
