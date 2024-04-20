#include <iostream>

using namespace std;

// Definição do struct No
struct No {
    int valor;
    No* anterior;
    No* proximo;
};

// Definição da Lista Duplamente Encadeada Circular
struct ListaDuplamenteEncadeadaCircular {
    No* inicio;
};

// Função para verificar se um valor está contido na lista
bool contido(int k, ListaDuplamenteEncadeadaCircular* L) {
    if (L->inicio == nullptr)
        return false;

    No* atual = L->inicio;

    // Percorre a lista até voltar ao início ou encontrar o valor
    do {
        if (atual->valor == k)
            return true;
        atual = atual->proximo;
    } while (atual != L->inicio);

    // Se o valor não for encontrado, retorna falso
    return false;
}

// Função para inserir um valor no final da lista
void inserir(int k, ListaDuplamenteEncadeadaCircular* L) {
    No* novo = new No;
    novo->valor = k;

    if (L->inicio == nullptr) {
        // Se a lista estiver vazia, o novo nó será o início e apontará para si mesmo
        novo->anterior = novo;
        novo->proximo = novo;
        L->inicio = novo;
    } else {
        // Caso contrário, o novo nó será inserido após o último nó e antes do início
        No* ultimo = L->inicio->anterior;
        novo->proximo = L->inicio;
        novo->anterior = ultimo;
        ultimo->proximo = novo;
        L->inicio->anterior = novo;
    }
}

// Função para remover o último nó da lista
void remover(ListaDuplamenteEncadeadaCircular* L) {
    // Se a lista estiver vazia, não há nada para remover
    if (L->inicio == nullptr) {
        cout << "Lista vazia. Não há elementos para remover." << endl;
        return;
    }

    No* ultimo = L->inicio->anterior;
    No* penultimo = ultimo->anterior;

    // Se houver apenas um elemento na lista, removemos e atualizamos o início da lista
    if (ultimo == L->inicio) {
        delete ultimo;
        L->inicio = nullptr;
    } else {
        // Caso contrário, removemos o último elemento, atualizamos as referências e liberamos a memória
        penultimo->proximo = L->inicio;
        L->inicio->anterior = penultimo;
        delete ultimo;
    }
}

int main() {
    // Inicializa a lista duplamente encadeada circular
    ListaDuplamenteEncadeadaCircular lista;
    lista.inicio = nullptr;

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
