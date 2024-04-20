#include <iostream>

// Definição da estrutura do nó
struct No {
    int valor;
    No* proximo;
};

// Função para imprimir uma lista
void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != nullptr) {
        std::cout << atual->valor << " ";
        atual = atual->proximo;
    }
    std::cout << std::endl;
}

// Função para inserir um elemento em ordem crescente na lista
No* inserirOrdenado(No* cabeca, int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = nullptr;

    // Caso a lista esteja vazia ou o valor seja menor que o primeiro elemento
    if (cabeca == nullptr || valor < cabeca->valor) {
        novoNo->proximo = cabeca;
        return novoNo;
    }

    // Encontra o nó onde o novo valor deve ser inserido
    No* anterior = nullptr;
    No* atual = cabeca;
    while (atual != nullptr && atual->valor < valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Insere o novo nó na posição correta
    anterior->proximo = novoNo;
    novoNo->proximo = atual;

    return cabeca;
}

// Função para intercalar duas listas ordenadas
No* intercalarOrdenado(No* lista1, No* lista2) {
    No* cabecaInterpolada = nullptr;
    No* apontador = cabecaInterpolada;

    // Intercala os nós das duas listas até uma delas acabar
    while (lista1 != nullptr && lista2 != nullptr) {
        if (lista1->valor < lista2->valor) {
            apontador = lista1;
            lista1 = lista1->proximo;
        } else {
            apontador = lista2;
            lista2 = lista2->proximo;
        }
        apontador = apontador->proximo;
    }
    // Adiciona os elementos restantes de uma das listas, caso haja algum
    imprimirLista(apontador);
    if (lista1 != nullptr){
        while (lista1 != nullptr) {
            apontador = lista1;
            lista1 = lista1->proximo;
            apontador = apontador->proximo;
    }
    }
    if(lista2 != nullptr){
        while (lista2 != nullptr) {
            apontador = lista2;
            lista2 = lista2->proximo;
            apontador = apontador->proximo;
        }
    }


    // Retorna o ponteiro para a lista intercalada
    return cabecaInterpolada;
}

int main() {
    // Criando a primeira lista ordenada: 1 -> 3 -> 5 -> 7 -> 9
    No* lista1 = nullptr;
    for (int i = 1; i <= 9; i += 2) {
        lista1 = inserirOrdenado(lista1, i);
    }

    // Criando a segunda lista ordenada: 2 -> 4 -> 6 -> 8 -> 10
    No* lista2 = nullptr;
    for (int i = 0; i <= 16; i += 2) {
        lista2 = inserirOrdenado(lista2, i);
    }

    // Imprimindo as listas originais
    std::cout << "Lista 1: ";
    imprimirLista(lista1);
    std::cout << "Lista 2: ";
    imprimirLista(lista2);

    // Intercalando as listas ordenadas e imprimindo o resultado
    No* listaInterpolada = intercalarOrdenado(lista1, lista2);
    std::cout << "Lista intercalada ordenada: ";
    imprimirLista(listaInterpolada);

    return 0;
}
