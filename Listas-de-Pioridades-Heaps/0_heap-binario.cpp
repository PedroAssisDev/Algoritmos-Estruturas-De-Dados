#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // Função para obter o índice do pai de um nó
    int parent(int i) { return (i - 1) / 2; }

    // Função para obter o índice do filho esquerdo de um nó
    int leftChild(int i) { return 2 * i + 1; }

    // Função para obter o índice do filho direito de um nó
    int rightChild(int i) { return 2 * i + 2; }

    // Função para reorganizar o heap após inserção
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Função para reorganizar o heap após remoção
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

public:
    // Função para inserir um elemento no heap
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Função para remover o menor elemento (a raiz) do heap
    int extractMin() {
        if (heap.size() == 0) {
            throw std::runtime_error("Heap is empty");
        }

        int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return result;
    }

    // Função para visualizar o heap
    void printHeap() {
        for (int i = 0; i < heap.size(); i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap heap;

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    std::cout << "Heap após inserções: ";
    heap.printHeap();

    std::cout << "Minimo extraído: " << heap.extractMin() << std::endl;
    std::cout << "Heap após extração: ";
    heap.printHeap();

    return 0;
}
