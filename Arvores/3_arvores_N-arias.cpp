#include <iostream>
#include <queue>

// Definição da estrutura do nó
struct NoArvore {
    int chave;              // Chave do nó
    NoArvore* filhos;       // Ponteiro para o primeiro filho
    NoArvore* listaIrmaos;  // Ponteiro para o próximo irmão
};

// Função para criar um novo nó
NoArvore* criarNo(int chave) {
    NoArvore* novoNo = new NoArvore;  // Aloca memória para um novo nó
    novoNo->chave = chave;            // Define a chave do nó
    novoNo->filhos = nullptr;         // Inicializa o ponteiro filhos como nullptr
    novoNo->listaIrmaos = nullptr;    // Inicializa o ponteiro listaIrmaos como nullptr
    return novoNo;                    // Retorna o ponteiro para o novo nó
}

// Função para adicionar um filho a um nó pai
void adicionarFilho(NoArvore* pai, int chaveFilho) {
    NoArvore* novoFilho = criarNo(chaveFilho);  // Cria um novo nó filho
    if (pai->filhos == nullptr) {
        // Se o pai não tem filhos, adiciona o novo filho diretamente
        pai->filhos = novoFilho;
    } else {
        // Se o pai já tem filhos, encontra o último filho e adiciona o novo filho como irmão
        NoArvore* temp = pai->filhos;
        while (temp->listaIrmaos != nullptr) {
            temp = temp->listaIrmaos;
        }
        temp->listaIrmaos = novoFilho;
    }
}

// Função para buscar um nó com uma chave específica (busca em profundidade)
NoArvore* buscarNo(NoArvore* raiz, int chave) {
    if (raiz == nullptr) return nullptr;          // Se a árvore está vazia, retorna nullptr
    if (raiz->chave == chave) return raiz;        // Se encontrou o nó, retorna o ponteiro para ele

    // Percorre os filhos do nó atual recursivamente
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        NoArvore* resultado = buscarNo(temp, chave);  // Busca recursiva no filho atual
        if (resultado != nullptr) return resultado;   // Se encontrou o nó, retorna o ponteiro para ele
        temp = temp->listaIrmaos;                     // Move para o próximo irmão
    }
    return nullptr;  // Se não encontrou o nó, retorna nullptr
}

// Função para percorrer e imprimir a árvore (em profundidade)
void percorrerArvore(NoArvore* raiz, int nivel = 0) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Imprime a chave do nó com indentação baseada no nível do nó
    for (int i = 0; i < nivel; ++i) {
        std::cout << "  ";
    }
    std::cout << raiz->chave << std::endl;

    // Percorre recursivamente os filhos do nó atual
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        percorrerArvore(temp, nivel + 1);  // Chamada recursiva para o próximo nível
        temp = temp->listaIrmaos;          // Move para o próximo irmão
    }
}

// Função para contar o número de nós na árvore
int contarNos(NoArvore* raiz) {
    if (raiz == nullptr) return 0;  // Se a árvore está vazia, retorna 0

    int count = 1;  // Conta o nó raiz
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        count += contarNos(temp);  // Soma o número de nós dos filhos recursivamente
        temp = temp->listaIrmaos;  // Move para o próximo irmão
    }
    return count;  // Retorna a contagem total de nós
}

// Função para verificar se um nó é folha
bool isFolha(NoArvore* no) {
    return no->filhos == nullptr;  // Um nó é folha se não tem filhos
}

// Função para remover um nó da árvore (simplificado)
void removerNo(NoArvore*& raiz, int chave) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Se o nó a ser removido é a raiz
    if (raiz->chave == chave) {
        std::cerr << "Remoção da raiz não suportada diretamente neste exemplo.\n";
        return;
    }

    // Busca o nó a ser removido e seu pai
    NoArvore* parent = nullptr;
    NoArvore* temp = raiz;
    std::queue<NoArvore*> q;
    q.push(temp);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        NoArvore* child = temp->filhos;
        NoArvore* prev = nullptr;
        while (child != nullptr) {
            if (child->chave == chave) {
                // Remove o nó ajustando os ponteiros do pai e dos irmãos
                if (prev == nullptr) {
                    temp->filhos = child->listaIrmaos;
                } else {
                    prev->listaIrmaos = child->listaIrmaos;
                }
                delete child;  // Libera a memória do nó removido
                return;
            }
            prev = child;
            child = child->listaIrmaos;
        }

        // Adiciona os filhos do nó atual à fila para busca em largura
        child = temp->filhos;
        while (child != nullptr) {
            q.push(child);
            child = child->listaIrmaos;
        }
    }
}

// Função para liberar a memória da árvore
void liberarArvore(NoArvore* raiz) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Libera a memória dos filhos recursivamente
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        NoArvore* proxIrmao = temp->listaIrmaos;
        liberarArvore(temp);  // Chamada recursiva para liberar a memória do filho
        temp = proxIrmao;     // Move para o próximo irmão
    }
    delete raiz;  // Libera a memória do nó atual
}

int main() {
    // Cria a árvore e adiciona nós
    NoArvore* raiz = criarNo(1);
    adicionarFilho(raiz, 2);
    adicionarFilho(raiz, 3);
    NoArvore* filho2 = buscarNo(raiz, 2);
    adicionarFilho(filho2, 4);
    adicionarFilho(filho2, 5);
    NoArvore* filho3 = buscarNo(raiz, 3);
    adicionarFilho(filho3, 6);
    adicionarFilho(filho3, 7);

    // Percorre e imprime a árvore
    std::cout << "Árvore n-ária:" << std::endl;
    percorrerArvore(raiz);

    // Conta o número de nós
    std::cout << "Número de nós na árvore: " << contarNos(raiz) << std::endl;

    // Verifica se um nó é folha
    std::cout << "O nó com chave 4 é folha? " << (isFolha(buscarNo(raiz, 4)) ? "Sim" : "Não") << std::endl;

    // Remove um nó
    std::cout << "Removendo o nó com chave 2" << std::endl;
    removerNo(raiz, 2);
    percorrerArvore(raiz);

    // Libera a memória da árvore
    liberarArvore(raiz);

    return 0;
}
