#include <iostream>

using namespace std;

// Definição do struct No
struct No {
    int valor;
    No* proximo;
};

// Definição da Pilha com Lista Simplesmente Encadeada
struct Pilha {
    No* topo;
};

// Função para inserir um valor no topo da pilha
void inserir(int k, Pilha* L) {
    No* novo = new No;
    novo->valor = k;
    novo->proximo = L->topo;
    L->topo = novo;
}

// Função para remover o valor do topo da pilha
void remover(Pilha* L) {
    // Se a pilha estiver vazia, não há nada para remover
    if (L->topo == nullptr) {
        cout << "Pilha vazia. Não há elementos para remover." << endl;
        return;
    }

    No* temp = L->topo;
    L->topo = L->topo->proximo;
    delete temp;
}

int main() {
    // Inicializa a pilha
    Pilha pilha;
    pilha.topo = nullptr;

    // Insere alguns valores na pilha
    inserir(5, &pilha);
    inserir(10, &pilha);
    inserir(15, &pilha);

    // Remove o topo da pilha
    remover(&pilha);

    return 0;
}
