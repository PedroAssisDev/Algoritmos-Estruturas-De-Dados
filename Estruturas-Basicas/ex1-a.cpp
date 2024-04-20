#include <iostream>

using namespace std;

// Definição do struct No
struct No {
    int valor;
    No* anterior;
    No* proximo;
};

// Definição da Lista Duplamente Encadeada
struct ListaDuplamenteEncadeada {
    No* inicio;
    No* fim;
};

// Função para verificar se um valor está contido na lista
bool contido(int k, ListaDuplamenteEncadeada* L) {
    No* atual = L->inicio;

    // Percorre a lista até encontrar o valor ou alcançar o final
    while (atual != nullptr) {
        if (atual->valor == k)
            return true;
        atual = atual->proximo;
    }

    // Se o valor não for encontrado, retorna falso
    return false;
}

// Função para inserir um valor no final da lista
void inserir(int k, ListaDuplamenteEncadeada* L) {
    No* novo = new No;
    novo->valor = k;
    novo->proximo = nullptr;

    // Se a lista estiver vazia, o novo nó será tanto o início quanto o fim da lista
    if (L->inicio == nullptr) {
        novo->anterior = nullptr;
        L->inicio = novo;
    } else {
        // Caso contrário, o novo nó será inserido após o último nó
        novo->anterior = L->fim;
        L->fim->proximo = novo;
    }

    L->fim = novo;
}

// Função para remover o último valor da lista
void remover(ListaDuplamenteEncadeada* L) {
    // Se a lista estiver vazia, não há nada para remover
    if (L->inicio == nullptr) {
        cout << "Lista vazia. Não há elementos para remover." << endl;
        return;
    }

    No* ultimo = L->fim;

    // Se houver apenas um elemento na lista, removemos e atualizamos o início e o fim da lista
    if (L->inicio == L->fim) {
        delete ultimo;
        L->inicio = nullptr;
        L->fim = nullptr;
    } else {
        // Caso contrário, removemos o último elemento, atualizamos o fim da lista e liberamos a memória
        L->fim = ultimo->anterior;
        L->fim->proximo = nullptr;
        delete ultimo;
    }
}

int main() {
    // Inicializa a lista duplamente encadeada
    ListaDuplamenteEncadeada lista;
    lista.inicio = nullptr;
    lista.fim = nullptr;

    // Insere alguns valores na lista
    inserir(5, &lista);
    inserir(10, &lista);
    inserir(15, &lista);

    // Verifica se um valor está contido na lista
    int valor = 10;
    if (contido(valor, &lista)) {
        cout << "O valor " << valor << " está contido na lista." << endl;
    } else {
        cout << "O valor " << valor << " não está contido na lista." << endl;
    }

    // Remove o último elemento da lista
    remover(&lista);

    return 0;
}
