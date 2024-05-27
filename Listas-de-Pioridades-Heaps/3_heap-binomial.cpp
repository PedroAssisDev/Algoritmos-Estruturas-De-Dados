#include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

using namespace std;

// Estrutura de um nó de árvore binomial
struct BinomialTreeNode {
    int key;                        // Chave do nó
    int degree;                     // Grau do nó (número de filhos)
    BinomialTreeNode* parent;       // Ponteiro para o nó pai
    BinomialTreeNode* child;        // Ponteiro para o primeiro filho
    BinomialTreeNode* sibling;      // Ponteiro para o próximo irmão
};

// Função para criar um novo nó de árvore binomial
BinomialTreeNode* createNode(int key) {
    BinomialTreeNode* newNode = new BinomialTreeNode();
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = nullptr;
    newNode->child = nullptr;
    newNode->sibling = nullptr;
    return newNode;
}

// Função para mesclar duas árvores binomiais de grau igual
BinomialTreeNode* mergeTrees(BinomialTreeNode* tree1, BinomialTreeNode* tree2) {
    if (tree1->key > tree2->key) {
        swap(tree1, tree2);
    }
    tree2->parent = tree1;
    tree2->sibling = tree1->child;
    tree1->child = tree2;
    tree1->degree++;
    return tree1;
}

// Função para unir duas listas de árvores binomiais
vector<BinomialTreeNode*> unionHeap(vector<BinomialTreeNode*>& heap1, vector<BinomialTreeNode*>& heap2) {
    vector<BinomialTreeNode*> result;
    int i = 0, j = 0;
    // Itera sobre as duas listas de árvores binomiais
    while (i < heap1.size() && j < heap2.size()) {
        // Escolhe a árvore binomial com menor grau
        if (heap1[i]->degree < heap2[j]->degree) {
            result.push_back(heap1[i++]);
        } else {
            result.push_back(heap2[j++]);
        }
    }
    // Adiciona os elementos restantes da primeira lista
    while (i < heap1.size()) {
        result.push_back(heap1[i++]);
    }
    // Adiciona os elementos restantes da segunda lista
    while (j < heap2.size()) {
        result.push_back(heap2[j++]);
    }
    return result;
}

// Função para mesclar duas filas de prioridade binomiais
vector<BinomialTreeNode*> binomialHeapUnion(vector<BinomialTreeNode*>& heap1, vector<BinomialTreeNode*>& heap2) {
    vector<BinomialTreeNode*> mergedHeap;
    mergedHeap = unionHeap(heap1, heap2);
    if (mergedHeap.empty()) {
        return mergedHeap;
    }

    vector<BinomialTreeNode*> finalHeap;
    finalHeap.push_back(mergedHeap[0]);

    // Itera sobre a lista mesclada de árvores binomiais
    for (int i = 1; i < mergedHeap.size(); i++) {
        // Verifica se há árvores binomiais com o mesmo grau
        if (finalHeap.back()->degree == mergedHeap[i]->degree) {
            // Caso haja, mescla as duas árvores
            if (i + 1 < mergedHeap.size() && mergedHeap[i]->degree == mergedHeap[i + 1]->degree) {
                continue;
            }
            if (finalHeap.back()->key <= mergedHeap[i]->key) {
                finalHeap.back()->sibling = mergedHeap[i]->sibling;
                mergeTrees(finalHeap.back(), mergedHeap[i]);
            } else {
                mergedHeap[i]->sibling = finalHeap.back()->child;
                mergeTrees(mergedHeap[i], finalHeap.back());
                finalHeap.back() = mergedHeap[i];
            }
        } else {
            finalHeap.push_back(mergedHeap[i]);
        }
    }
    return finalHeap;
}

// Função para inserir um novo elemento em um heap binomial
vector<BinomialTreeNode*> binomialHeapInsert(vector<BinomialTreeNode*>& heap, int key) {
    vector<BinomialTreeNode*> newHeap;
    BinomialTreeNode* newNode = createNode(key);
    newHeap.push_back(newNode);
    return binomialHeapUnion(heap, newHeap);
}

// Função para encontrar o nó com a chave mínima em um heap binomial
BinomialTreeNode* findMinimumNode(vector<BinomialTreeNode*>& heap) {
    BinomialTreeNode* minNode = heap[0];
    // Itera sobre a lista de árvores binomiais
    for (int i = 1; i < heap.size(); i++) {
        // Atualiza o nó com a menor chave encontrada até agora
        if (heap[i]->key < minNode->key) {
            minNode = heap[i];
        }
    }
    return minNode;
}

// Função para extrair o nó com a chave mínima de um heap binomial
vector<BinomialTreeNode*> extractMinNode(vector<BinomialTreeNode*>& heap) {
    vector<BinomialTreeNode*> newHeap;
    BinomialTreeNode* minNode = findMinimumNode(heap);
    // Remove o nó com a chave mínima da lista de árvores binomiais
    for (auto node : heap) {
        if (node != minNode) {
            newHeap.push_back(node);
        }
    }
    // Reverte a lista de filhos do nó com a chave mínima para formar uma nova fila binomial
    vector<BinomialTreeNode*> children;
    BinomialTreeNode* child = minNode->child;
    while (child != nullptr) {
        BinomialTreeNode* nextSibling = child->sibling;
        child->sibling = nullptr;
        children.push_back(child);
        child = nextSibling;
    }
    // Reverte a lista de filhos para manter a propriedade de heap binomial
    reverse(children.begin(), children.end());
    // Unir a nova lista de árvores binomiais com a lista original (sem o nó com a chave mínima)
    return binomialHeapUnion(newHeap, children);
}

// Função para imprimir uma árvore binomial
void printBinomialTree(BinomialTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->key << " ";
    printBinomialTree(root->child);
    printBinomialTree(root->sibling);
}

// Função para imprimir um heap binomial
void printBinomialHeap(vector<BinomialTreeNode*>& heap) {
    cout << "Binomial Heap: ";
    for (auto tree : heap) {
        printBinomialTree(tree);
    }
    cout << endl;
}


int main() {
    vector<BinomialTreeNode*> binomialHeap;

    // Inserindo elementos no heap binomial
    binomialHeap = binomialHeapInsert(binomialHeap, 10);
    binomialHeap = binomialHeapInsert(binomialHeap, 20);
    binomialHeap = binomialHeapInsert(binomialHeap, 5);
    binomialHeap = binomialHeapInsert(binomialHeap, 25);
    binomialHeap = binomialHeapInsert(binomialHeap, 4);
    binomialHeap = binomialHeapInsert(binomialHeap, 30);
    binomialHeap = binomialHeapInsert(binomialHeap, 13);
    binomialHeap = binomialHeapInsert(binomialHeap, 12);
    binomialHeap = binomialHeapInsert(binomialHeap, 3);
    binomialHeap = binomialHeapInsert(binomialHeap, 3333);
    binomialHeap = binomialHeapInsert(binomialHeap, 44);


    // Imprimindo o heap binomial após a inserção
    cout << "Heap binomial após a inserção: ";
    printBinomialHeap(binomialHeap);

    // Encontrando o nó com a chave mínima no heap binomial
    BinomialTreeNode* minNode = findMinimumNode(binomialHeap);
    cout << "\nChave mínima no heap binomial: " << minNode->key << "\n\n";

    // Extraindo o nó com a chave mínima do heap binomial
    cout << "Extraindo o nó com a chave mínima do heap binomial...\n";
    binomialHeap = extractMinNode(binomialHeap);
    cout << "Heap binomial após a extração: ";
    printBinomialHeap(binomialHeap);

    return 0;
}