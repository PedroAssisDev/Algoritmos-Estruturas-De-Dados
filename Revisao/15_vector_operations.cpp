#include <iostream>
#include <vector>
#include <algorithm> // Para usar a função de ordenação

using namespace std;

int main() {
    // Inicialização de um vetor de inteiros
    vector<int> vetor = {5, 2, 9, 1, 7};

    // Acesso aos elementos do vetor
    cout << "Elemento na posição 2: " << vetor[2] << endl;

    // Iteração sobre os elementos do vetor
    cout << "Elementos do vetor: ";
    for (int elem : vetor) {
        cout << elem << " ";
    }
    cout << endl;

    // Inserção de um elemento no final do vetor
    vetor.push_back(10);

    // Remoção de um elemento do vetor
    vetor.pop_back();

    // Ordenação dos elementos do vetor (em ordem crescente)
    sort(vetor.begin(), vetor.end());

    // Busca por um elemento no vetor
    int elemento = 7;
    auto it = find(vetor.begin(), vetor.end(), elemento);
    if (it != vetor.end()) {
        cout << "Elemento " << elemento << " encontrado no vetor." << endl;
    } else {
        cout << "Elemento " << elemento << " não encontrado no vetor." << endl;
    }

    // Exibição dos elementos do vetor após as operações
    cout << "Elementos do vetor após as operações: ";
    for (int elem : vetor) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
