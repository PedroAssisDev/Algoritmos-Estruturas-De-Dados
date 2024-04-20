#include <iostream>

// Definição da estrutura do nó da lista encadeada
struct No {
    int info;     // Informação armazenada no nó
    No* prox;     // Ponteiro para o próximo nó
};

// Função para inserir um elemento no final da lista
void inserirElemento(No*& ptLista, int valor) {
    No* novoNo = new No;           // Cria um novo nó
    novoNo->info = valor;          // Atribui o valor ao novo nó
    novoNo->prox = nullptr;        // Define o próximo nó como nulo

    if (ptLista == nullptr) {      // Se a lista estiver vazia
        ptLista = novoNo;          // O novo nó é o primeiro da lista
    } else {
        No* temp = ptLista;        // Ponteiro temporário para percorrer a lista
        while (temp->prox != nullptr) {   // Encontra o último nó da lista
            temp = temp->prox;
        }
        temp->prox = novoNo;       // Adiciona o novo nó ao final da lista
    }
}

// Função para imprimir os elementos da lista
void imprimirLista(No* ptLista) {
    No* temp = ptLista;            // Ponteiro temporário para percorrer a lista
    while (temp != nullptr) {      // Enquanto houver elementos na lista
        std::cout << temp->info << " ";   // Imprime o valor do nó atual
        temp = temp->prox;         // Move para o próximo nó
    }
    std::cout << std::endl;
}

// Função para buscar um elemento na lista
bool buscaElemento(No* ptLista, int valor) {
    No* temp = ptLista;            // Ponteiro temporário para percorrer a lista
    while (temp != nullptr) {      // Enquanto houver elementos na lista
        if (temp->info == valor) { // Se encontrar o valor
            return true;           // Retorna verdadeiro
        }
        temp = temp->prox;         // Move para o próximo nó
    }
    return false;                  // Valor não encontrado
}

// Função para remover o primeiro elemento da lista
void removerElemento(No*& ptLista) {
    if (ptLista != nullptr) {      // Se a lista não estiver vazia
        No* temp = ptLista;        // Ponteiro temporário para o primeiro nó
        ptLista = ptLista->prox;   // Atualiza o ponteiro para o primeiro nó
        delete temp;               // Libera a memória alocada para o nó removido
    }
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

    // Buscando elementos na lista
    std::cout << "Buscando elemento 20: " << (buscaElemento(ptLista, 20) ? "Encontrado" : "Não encontrado") << std::endl;  // Saída: Encontrado
    std::cout << "Buscando elemento 40: " << (buscaElemento(ptLista, 40) ? "Encontrado" : "Não encontrado") << std::endl;  // Saída: Não encontrado

    // Removendo o primeiro elemento da lista
    removerElemento(ptLista);

    // Imprimindo a lista após a remoção
    std::cout << "Lista após remoção: ";
    imprimirLista(ptLista);  // Saída: 20 30

    return 0;
}
