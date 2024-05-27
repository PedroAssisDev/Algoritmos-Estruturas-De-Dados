#include <iostream>
#include <queue>

// Definição da estrutura do nó
struct NoArvore {
    int chave;              // Chave do nó
    NoArvore* esquerda;     // Ponteiro para o filho esquerdo
    NoArvore* meio;         // Ponteiro para o filho do meio
    NoArvore* direita;      // Ponteiro para o filho direito
};

// Função para criar um novo nó
NoArvore* criarNo(int chave) {
    NoArvore* novoNo = new NoArvore;  // Aloca memória para um novo nó
    novoNo->chave = chave;            // Define a chave do nó
    novoNo->esquerda = nullptr;       // Inicializa o ponteiro esquerda como nullptr
    novoNo->meio = nullptr;           // Inicializa o ponteiro meio como nullptr
    novoNo->direita = nullptr;        // Inicializa o ponteiro direita como nullptr
    return novoNo;                    // Retorna o ponteiro para o novo nó
}

// Função para adicionar um filho à esquerda, meio ou direita de um nó pai
void adicionarFilho(NoArvore* pai, int chaveFilho, char posicao) {
    NoArvore* novoFilho = criarNo(chaveFilho);  // Cria um novo nó filho
    if (posicao == 'E') {
        // Adiciona o filho à esquerda
        if (pai->esquerda == nullptr) {
            pai->esquerda = novoFilho;
        } else {
            std::cerr << "Já existe um nó na posição esquerda.\n";
        }
    } else if (posicao == 'M') {
        // Adiciona o filho ao meio
        if (pai->meio == nullptr) {
            pai->meio = novoFilho;
        } else {
            std::cerr << "Já existe um nó na posição meio.\n";
        }
    } else if (posicao == 'D') {
        // Adiciona o filho à direita
        if (pai->direita == nullptr) {
            pai->direita = novoFilho;
        } else {
            std::cerr << "Já existe um nó na posição direita.\n";
        }
    } else {
        std::cerr << "Posição inválida. Use 'E' para esquerda, 'M' para meio ou 'D' para direita.\n";
    }
}

// Função para buscar um nó com uma chave específica (busca em profundidade)
NoArvore* buscarNo(NoArvore* raiz, int chave) {
    if (raiz == nullptr) return nullptr;  // Se a árvore está vazia, retorna nullptr
    if (raiz->chave == chave) return raiz;  // Se encontrou o nó, retorna o ponteiro para ele

    // Busca recursivamente nos filhos esquerdo, meio e direito
    NoArvore* resultado = buscarNo(raiz->esquerda, chave);
    if (resultado != nullptr) return resultado;
    resultado = buscarNo(raiz->meio, chave);
    if (resultado != nullptr) return resultado;
    return buscarNo(raiz->direita, chave);
}

// Função para percorrer e imprimir a árvore (em profundidade)
void percorrerArvore(NoArvore* raiz, int nivel = 0) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Imprime a chave do nó com indentação baseada no nível do nó
    for (int i = 0; i < nivel; ++i) {
        std::cout << "  ";
    }
    std::cout << raiz->chave << std::endl;

    // Percorre recursivamente os filhos esquerdo, meio e direito
    percorrerArvore(raiz->esquerda, nivel + 1);
    percorrerArvore(raiz->meio, nivel + 1);
    percorrerArvore(raiz->direita, nivel + 1);
}

// Função para contar o número de nós na árvore
int contarNos(NoArvore* raiz) {
    if (raiz == nullptr) return 0;  // Se a árvore está vazia, retorna 0

    // Conta o nó atual e soma recursivamente os nós dos filhos esquerdo, meio e direito
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->meio) + contarNos(raiz->direita);
}

// Função para verificar se um nó é folha
bool isFolha(NoArvore* no) {
    return no->esquerda == nullptr && no->meio == nullptr && no->direita == nullptr;  // Um nó é folha se não tem filhos
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

        NoArvore* child = temp->esquerda;
        if (child != nullptr && child->chave == chave) {
            delete child;
            temp->esquerda = nullptr;
            return;
        }
        if (child != nullptr) q.push(child);

        child = temp->meio;
        if (child != nullptr && child->chave == chave) {
            delete child;
            temp->meio = nullptr;
            return;
        }
        if (child != nullptr) q.push(child);

        child = temp->direita;
        if (child != nullptr && child->chave == chave) {
            delete child;
            temp->direita = nullptr;
            return;
        }
        if (child != nullptr) q.push(child);
    }
}

// Função para liberar a memória da árvore
void liberarArvore(NoArvore* raiz) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Libera a memória dos filhos recursivamente
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->meio);
    liberarArvore(raiz->direita);

    delete raiz;  // Libera a memória do nó atual
}

int main() {
    // Cria a árvore e adiciona nós
    NoArvore* raiz = criarNo(1);
    adicionarFilho(raiz, 2, 'E');
    adicionarFilho(raiz, 3, 'M');
    adicionarFilho(raiz, 4, 'D');
    NoArvore* filho2 = buscarNo(raiz, 2);
    adicionarFilho(filho2, 5, 'E');
    adicionarFilho(filho2, 6, 'M');
    adicionarFilho(filho2, 7, 'D');
    NoArvore* filho3 = buscarNo(raiz, 3);
    adicionarFilho(filho3, 8, 'E');
    adicionarFilho(filho3, 9, 'M');
    adicionarFilho(filho3, 10, 'D');

    // Percorre e imprime a árvore
    std::cout << "Árvore ternária:" << std::endl;
    percorrerArvore(raiz);

    // Conta o número de nós
    std::cout << "Número de nós na árvore: " << contarNos(raiz) << std::endl;

    // Verifica se um nó é folha
    std::cout << "O nó com chave 5 é folha? " << (isFolha(buscarNo(raiz, 5)) ? "Sim" : "Não") << std::endl;

    // Remove um nó
    std::cout << "Removendo o nó com chave 2" << std::endl;
    removerNo(raiz, 2);
    percorrerArvore(raiz);

    // Libera a memória da árvore
    liberarArvore(raiz);

    return 0;
}
