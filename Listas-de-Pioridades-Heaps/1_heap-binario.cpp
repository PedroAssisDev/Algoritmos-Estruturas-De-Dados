#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

class MinHeap {
private:
    std::vector<int> heap;  // Vetor para armazenar os elementos do heap

    // Função para obter o índice do pai de um nó
    int parent(int i) { return (i - 1) / 2; }

    // Função para obter o índice do filho esquerdo de um nó
    int leftChild(int i) { return 2 * i + 1; }

    // Função para obter o índice do filho direito de um nó
    int rightChild(int i) { return 2 * i + 2; }

    // Função para reorganizar o heap de baixo para cima após a inserção
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Função para reorganizar o heap de cima para baixo após a remoção
    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }

        int right = rightChild(i);
        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }

        if (i != minIndex) {
            std::swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

    // Função auxiliar para imprimir o heap como árvore
    void printHeapTree(int i, int indent = 0) {
        if (i < heap.size()) {
            if (rightChild(i) < heap.size()) {
                printHeapTree(rightChild(i), indent + 4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (rightChild(i) < heap.size()) {
                std::cout << " /\n" << std::setw(indent) << ' ';
            }
            std::cout << heap[i] << "\n ";
            if (leftChild(i) < heap.size()) {
                std::cout << std::setw(indent) << ' ' << " \\\n";
                printHeapTree(leftChild(i), indent + 4);
            }
        }
    }

public:
    // Função para inserir um elemento no heap
    void insert(int key) {
        heap.push_back(key);          // Adiciona a nova chave ao final do vetor
        heapifyUp(heap.size() - 1);   // Restaura a propriedade do heap de baixo para cima
    }

    // Função para remover o menor elemento (a raiz) do heap
    int extractMin() {
        if (heap.size() == 0) {
            throw std::runtime_error("Heap está vazio");
        }

        int result = heap[0];          // Armazena o menor elemento
        heap[0] = heap.back();         // Move o último elemento para a raiz
        heap.pop_back();               // Remove o último elemento
        heapifyDown(0);                // Restaura a propriedade do heap de cima para baixo

        return result;                 // Retorna o menor elemento
    }

    // Função para obter o menor elemento sem removê-lo
    int getMin() {
        if (heap.size() == 0) {
            throw std::runtime_error("Heap está vazio");
        }
        return heap[0];                // Retorna a raiz do heap
    }

    // Função para alterar a chave de um elemento
    void changeKey(int i, int new_val) {
        int old_val = heap[i];
        heap[i] = new_val;
        if (new_val < old_val) {
            heapifyUp(i);              // Restaura a propriedade do heap se a nova chave é menor
        } else {
            heapifyDown(i);            // Restaura a propriedade do heap se a nova chave é maior
        }
    }

    // Função para remover um elemento arbitrário do heap
    void remove(int i) {
        changeKey(i, getMin() - 1);    // Diminui a chave do elemento para menor que a chave mínima
        extractMin();                  // Remove o menor elemento (que agora é o elemento de interesse)
    }

    // Função para verificar se o heap está vazio
    bool isEmpty() const {
        return heap.size() == 0;
    }

    // Função para visualizar o heap como árvore
    void printHeapTree() {
        if (!heap.empty()) {
            printHeapTree(0);
        }
    }

    // Função para visualizar o heap como vetor
    void printHeap() {
        for (int i = 0; i < heap.size(); i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap heap;

    // Inserir elementos no heap
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    // Visualizar o heap após inserções
    std::cout << "Heap após inserções: ";
    heap.printHeap();

    // Visualizar o heap como árvore
    std::cout << "Heap como árvore:\n";
    heap.printHeapTree();

    // Extrair o mínimo
    std::cout << "Minimo extraído: " << heap.extractMin() << std::endl;

    // Visualizar o heap após extração
    std::cout << "Heap após extração: ";
    heap.printHeap();

    // Alterar a chave de um elemento
    heap.changeKey(2, 1);
    std::cout << "Heap após alterar chave: ";
    heap.printHeap();

    // Remover um elemento arbitrário
    heap.remove(3);
    std::cout << "Heap após remover elemento: ";
    heap.printHeap();

    // Verificar se o heap está vazio
    std::cout << "O heap está vazio? " << (heap.isEmpty() ? "Sim" : "Não") << std::endl;

    return 0;
}
