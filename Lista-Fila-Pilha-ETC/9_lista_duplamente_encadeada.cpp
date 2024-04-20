#include <iostream>

// Definição da estrutura do nó da lista encadeada
struct No {
    int info;     // Informação armazenada no nó
    No* ant;      // Ponteiro para o nó anterior
    No* post;     // Ponteiro para o próximo nó
};

// Função para inserir um elemento na lista
void inserirElemento(No*& ptLista, int valor) {
    No* novoNo = new No;           // Cria um novo nó
    novoNo->info = valor;          // Atribui o valor ao novo nó

    // Se a lista estiver vazia
    if (ptLista == nullptr) {
        novoNo->ant = novoNo;      // O ponteiro anterior do novo nó aponta para ele mesmo
        novoNo->post = novoNo;     // O ponteiro posterior do novo nó aponta para ele mesmo
        ptLista = novoNo;          // O novo nó é o primeiro da lista
    } else {
        novoNo->ant = ptLista->ant;    // O ponteiro anterior do novo nó aponta para o último nó da lista
        novoNo->post = ptLista;        // O ponteiro posterior do novo nó aponta para o primeiro nó da lista
        ptLista->ant = novoNo->post;   // O ponteiro posterior do último nó da lista aponta para o novo nó
        ptLista->ant = novoNo;         // O ponteiro anterior do primeiro nó da lista aponta para o novo nó
    }
}

// Função para imprimir os elementos da lista
void imprimirLista(No* ptLista) {
    No* temp = ptLista;     // Ponteiro temporário para percorrer a lista

    // Percorre a lista a partir do primeiro nó
    do {
        std::cout << temp->info << " ";   // Imprime o valor do nó atual
        temp = temp->post;     // Move para o próximo nó
    } while (temp != ptLista);  // Repete até voltar ao primeiro nó
    std::cout << std::endl;
}

// Função para remover um elemento da lista
void removerElemento(No*& ptLista, int valor) {
    if (ptLista == nullptr) {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    No* temp = ptLista;     // Ponteiro temporário para percorrer a lista

    // Percorre a lista até encontrar o elemento ou voltar ao primeiro nó
    do {
        if (temp->info == valor) {
            // Se o elemento for encontrado

            // Se o nó a ser removido não é o primeiro da lista
            if (temp->ant != temp) {
                temp->ant->post = temp->post;   // O nó anterior ao nó a ser removido aponta para o próximo nó
                temp->post->ant = temp->ant;   // O nó seguinte ao nó a ser removido aponta para o anterior
            } else {
                // Se o nó a ser removido é o primeiro da lista
                ptLista = temp->post;   // Atualiza o ponteiro para o primeiro nó da lista
                if (ptLista == temp) {
                    ptLista = nullptr;  // Se a lista contiver apenas um nó
                }
            }

            delete temp;   // Libera a memória alocada para o nó removido
            std::cout << "Elemento removido: " << valor << std::endl;
            return;
        }
        temp = temp->post;     // Move para o próximo nó
    } while (temp != ptLista);  // Repete até voltar ao primeiro nó

    std::cout << "Elemento nao encontrado na lista!" << std::endl;
}

int main() {
    No* ptLista = nullptr;  // Ponteiro para o primeiro nó da lista

    // Inserindo elementos na lista
    inserirElemento(ptLista, 10);
    inserirElemento(ptLista, 20);
    inserirElemento(ptLista, 30);

    // Imprimindo a lista
    std::cout << "Lista: ";
    imprimirLista(ptLista);  // Saída: 10 20 30

    // Removendo o elemento 20 da lista
    removerElemento(ptLista, 20);

    // Imprimindo a lista após a remoção
    std::cout << "Lista apos remocao: ";
    imprimirLista(ptLista);  // Saída: 10 30

    return 0;
}
