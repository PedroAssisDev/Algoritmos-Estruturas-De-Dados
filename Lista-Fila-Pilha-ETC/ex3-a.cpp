#include <iostream>
using namespace std;

// Definição do struct Nó
struct No {
    int valor;
    No* proximo;
};

// Função para inserir um valor no início de uma lista encadeada
void inserirInicio(int valor, No*& lista) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = lista;
    lista = novo;
}

// Função para percorrer L e construir L' com os valores de L em ordem inversa
No* construirListaInversa(No* L) {
    No* L_inversa = nullptr;

    // Percorre a lista L
    while (L != nullptr) {
        // Insere o valor atual no início de L'
        inserirInicio(L->valor, L_inversa);
        L = L->proximo; // Move para o próximo nó em L
    }

    return L_inversa;
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
    inserirInicio(3, L);
    inserirInicio(2, L);
    inserirInicio(1, L);

    // Construindo a lista inversa L'
    cout << "Lista  dos elementos de L:" << endl;
    imprimirLista(L);
    No* L_inversa = construirListaInversa(L);

    // Imprimindo L' para verificar se está em ordem inversa
    cout << "Lista inversa dos elementos de L:" << endl;
    imprimirLista(L_inversa);

    return 0;
}
