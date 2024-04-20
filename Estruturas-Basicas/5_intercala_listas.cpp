#include <iostream>

struct No {
    int valor;
    No* proximo;
};

// Função para inserir um elemento no início de uma lista
void inserirInicio(No*& cabeca, int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = cabeca;
    cabeca = novoNo;
}

// Função para imprimir uma lista
void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != nullptr) {
        std::cout << atual->valor << " ";
        atual = atual->proximo;
    }
    std::cout << std::endl;
}

// Função para intercalar duas listas simplesmente encadeadas
No* intercalarListas(No* lista1, No* lista2) {
    No* cabecaInterpolada = nullptr;
    No* apontador = cabecaInterpolada;

    // Intercala os nós das duas listas até uma delas acabar
    while (lista1 != nullptr && lista2 != nullptr) {
        apontador = lista1;      // Aponta para um nó da primeira lista
        lista1 = lista1->proximo;  // Avança para o próximo nó da primeira lista
        apontador->proximo = lista2;   // Aponta para um nó da segunda lista
        lista2 = lista2->proximo;  // Avança para o próximo nó da segunda lista
        apontador = apontador->proximo;
    }

    // Adiciona os elementos restantes de uma das listas, caso haja algum
    apontador->proximo = (lista1 != nullptr) ? lista1 : lista2;

    // Retorna o ponteiro para a lista intercalada
    return cabecaInterpolada;
}



int main() {
    // Criando a primeira lista: 1 -> 3 -> 5 -> 7 -> 9
    No* lista1 = nullptr;
    inserirInicio(lista1, 9);
    inserirInicio(lista1, 7);
    inserirInicio(lista1, 5);
    inserirInicio(lista1, 3);
    inserirInicio(lista1, 1);

    // Criando a segunda lista: 2 -> 4 -> 6 -> 8 -> 10
    No* lista2 = nullptr;
    inserirInicio(lista2, 10);
    inserirInicio(lista2, 8);
    inserirInicio(lista2, 6);
    inserirInicio(lista2, 4);
    inserirInicio(lista2, 2);

    // Imprimindo as listas originais
    std::cout << "Lista 1: ";
    imprimirLista(lista1);
    std::cout << "Lista 2: ";
    imprimirLista(lista2);

    // Intercalando as listas
    No* listaInterpolada = intercalarListas(lista1, lista2);

    // Imprimindo a lista resultante
    std::cout << "Lista intercalada: ";
    imprimirLista(listaInterpolada);

    return 0;
}
