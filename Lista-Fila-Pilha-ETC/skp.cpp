#include <iostream>
#include <cstdlib> // Para a função rand()

using namespace std;

// Definição do struct No
struct No {
    No *prox;
    No *desce;
    int x;
};

// Definição do struct SkipList
struct SkipList {
    No *head;
};

// Função para verificar se um valor está contido na SkipList
bool contido(No *head, int k) {
    No *atual = head;

    // Percorre a lista até encontrar o valor ou alcançar o final
    while (atual != nullptr && atual->x < k) {
        atual = atual->prox;
    }

    // Se o valor atual for igual a k, então k está na lista
    return (atual != nullptr && atual->x == k);
}

// Função para contar quantos valores menores que x existem na SkipList
int contaMenores(No *head, int x) {
    int count = 0;
    No *atual = head;

    // Percorre a lista e incrementa o contador para cada valor menor que x
    while (atual != nullptr && atual->x < x) {
        count++;
        atual = atual->prox;
    }

    return count;
}

// Função para imprimir os valores e níveis da SkipList
void imprimirSkipList(SkipList lista) {
    No *atualNivel = lista.head;

    // Percorre os níveis da SkipList
    while (atualNivel != nullptr) {
        No *atual = atualNivel;

        cout << "Nível: ";
        
        // Imprime os valores do nível atual
        while (atual != nullptr) {
            cout << " " << atual->x << " ";
            atual = atual->prox;
        }
        
        cout << endl;
        
        // Passa para o próximo nível
        atualNivel = atualNivel->desce;
    }
}


int main() {
    // Criação da SkipList com valores aleatórios
    SkipList lista;
    lista.head = nullptr;

    // Inserindo valores aleatórios na SkipList
    for (int i = 0; i < 100; i++) {
        No *novo = new No;
        novo->x = rand() % 100; // Valores aleatórios entre 0 e 19
        novo->prox = nullptr;
        novo->desce = nullptr;

        // Inserindo novo nó na lista
        if (lista.head == nullptr || novo->x < lista.head->x) {
            novo->prox = lista.head;
            lista.head = novo;
        } else {
            No *atual = lista.head;
            while (atual->prox != nullptr && atual->prox->x < novo->x) {
                atual = atual->prox;
            }
            novo->prox = atual->prox;
            atual->prox = novo;
        }
    }

    // Impressão dos valores e níveis da SkipList
    cout << "Valores e níveis na SkipList:" << endl;
    imprimirSkipList(lista);

    // Verificação se um valor está contido na SkipList
    int valor = 7;
    if (contido(lista.head, valor)) {
        cout << "O valor " << valor << " está contido na SkipList." << endl;
    } else {
        cout << "O valor " << valor << " não está contido na SkipList." << endl;
    }

    // Contagem de valores menores que um determinado valor na SkipList
    int valor_limite = 10;
    int quantidade = contaMenores(lista.head, valor_limite);
    cout << "Existem " << quantidade << " valores menores que " << valor_limite << " na SkipList." << endl;

    return 0;
}
