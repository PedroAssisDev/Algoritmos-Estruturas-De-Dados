#include<bits/stdc++.h>
using namespace std;

// Estrutura para representar um nó de um heap binomial
struct Node {
    int val, degree;
    Node *parent, *child, *sibling;
};

// Função para criar um novo nó
Node* newNode(int val) {
    Node *node = new Node;
    node->val = val;
    node->degree = 0;
    node->parent = node->child = node->sibling = NULL;
    return node;
}

// Função para mesclar duas árvores binomiais
Node* mergeBinomialTrees(Node *b1, Node *b2) {
    // Se a chave do primeiro nó for maior, troque os nós
    if (b1->val > b2->val)
        swap(b1, b2);

    // Faz o segundo nó ser filho do primeiro
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

// Função para fazer a união de dois heaps binomiais
list<Node*> unionBionomialHeap(list<Node*> l1, list<Node*> l2) {
    list<Node*> _new;
    list<Node*>::iterator it = l1.begin();
    list<Node*>::iterator ot = l2.begin();
    while (it != l1.end() && ot != l2.end()) {
        // Se o grau do primeiro nó for menor ou igual ao do segundo, insira o primeiro na nova lista e avance o iterador
        if((*it)->degree <= (*ot)->degree) {
            _new.push_back(*it);
            it++;
        } else {
            // Caso contrário, insira o segundo na nova lista e avance o iterador
            _new.push_back(*ot);
            ot++;
        }
    }

    // Insere os nós restantes da primeira lista na nova lista
    while (it != l1.end()) {
        _new.push_back(*it);
        it++;
    }

    // Insere os nós restantes da segunda lista na nova lista
    while (ot != l2.end()) {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}

// Função para ajustar o heap após a união
list<Node*> adjust(list<Node*> _heap) {
    if (_heap.size() <= 1)
        return _heap;
    list<Node*> new_heap;
    list<Node*>::iterator it1, it2, it3;
    it1 = it2 = it3 = _heap.begin();

    if (_heap.size() == 2) {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    } else {
        it2++;
        it3 = it2;
        it3++;
    }
    while (it1 != _heap.end()) {
        if (it2 == _heap.end())
            it1++;

        else if ((*it1)->degree < (*it2)->degree) {
            it1++;
            it2++;
            if(it3 != _heap.end())
                it3++;
        }

        else if (it3 != _heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree) {
            it1++;
            it2++;
            it3++;
        }

        else if ((*it1)->degree == (*it2)->degree) {
            Node *temp;
            *it1 = mergeBinomialTrees(*it1, *it2);
            it2 = _heap.erase(it2);
            if(it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}

// Função para inserir uma árvore em um heap
list<Node*> insertATreeInHeap(list<Node*> _heap, Node *tree) {
    list<Node*> temp;
    temp.push_back(tree);
    temp = unionBionomialHeap(_heap, temp);
    return adjust(temp);
}

// Função para remover o nó mínimo de uma árvore e retornar um heap binomial
list<Node*> removeMinFromTreeReturnBHeap(Node *tree) {
    list<Node*> heap;
    Node *temp = tree->child;
    Node *lo;

    while (temp) {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}

// Função para inserir um nó no heap
list<Node*> insert(list<Node*> _head, int key) {
    Node *temp = newNode(key);
    return insertATreeInHeap(_head, temp);
}

// Função para obter o nó mínimo do heap
Node* getMin(list<Node*> _heap) {
    list<Node*>::iterator it = _heap.begin();
    Node *temp = *it;
    it++;
    while (it != _heap.end()) {
        if ((*it)->val < temp->val)
            temp = *it;
        it++;
    }
    return temp;
}

// Função para extrair o nó mínimo do heap
list<Node*> extractMin(list<Node*> _heap) {
    list<Node*> new_heap, lo;
    Node *temp;

    temp = getMin(_heap);
    list<Node*>::iterator it;
    it = _heap.begin();
    while (it != _heap.end()) {
        if (*it != temp) {
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    new_heap = unionBionomialHeap(new_heap, lo);
    new_heap = adjust(new_heap);
    return new_heap;
}

// Função para imprimir uma árvore
void printTree(Node *h) {
    while (h) {
        cout << h->val << " ";
        printTree(h->child);
        h = h->sibling;
    }
}

// Função para imprimir um heap
void printHeap(list<Node*> _heap) {
    list<Node*> ::iterator it;
    it = _heap.begin();
    while (it != _heap.end()) {
        printTree(*it);
        it++;
    }
}

// Função principal
int main() {
    int ch, key;
    list<Node*> _heap;

    // Inserindo elementos no heap
    _heap = insert(_heap, 10);
    _heap = insert(_heap, 20);
    _heap = insert(_heap, 30);
    _heap = insert(_heap, 1);
    _heap = insert(_heap, 2);
    _heap = insert(_heap, 3);
    _heap = insert(_heap, 110);
    _heap = insert(_heap, 201);
    _heap = insert(_heap, 310);

    // Imprimindo os elementos do heap
    cout << "Heap elements after insertion:\n";
    printHeap(_heap);

    // Obtendo e imprimindo o elemento mínimo do heap
    Node *temp = getMin(_heap);
    cout << "\nMinimum element of heap " << temp->val << "\n";

    // Extraindo o elemento mínimo do heap e imprimindo o heap após a extração
    _heap = extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    printHeap(_heap);

    return 0;
}
