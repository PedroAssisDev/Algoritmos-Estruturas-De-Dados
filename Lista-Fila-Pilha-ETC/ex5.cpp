#include <iostream>
#include <vector>
using namespace std;

// Definição da estrutura de dados para a matriz esparsa
struct MatrizEsparsa {
    vector<double> valores;
    vector<int> colunas;
    vector<int> ponteiros_linhas;
    int num_linhas;
    int num_colunas;
};

// Função para inserir um elemento na matriz esparsa
void inserirElemento(MatrizEsparsa& matriz, int linha, int coluna, double valor) {
    // Verifica se a posição (linha, coluna) está dentro da matriz
    if (linha >= 0 && linha < matriz.num_linhas && coluna >= 0 && coluna < matriz.num_colunas) {
        // Insere o valor não nulo e sua coluna na lista de valores e colunas
        matriz.valores.push_back(valor);
        matriz.colunas.push_back(coluna);

        // Verifica se é o primeiro elemento da linha atual
        if (linha == 0 || matriz.ponteiros_linhas[linha] == 0) {
            matriz.ponteiros_linhas[linha] = matriz.valores.size() - 1;
        }
    }
}

// Função para buscar um elemento na matriz esparsa
double buscarElemento(const MatrizEsparsa& matriz, int linha, int coluna) {
    // Verifica se a posição (linha, coluna) está dentro da matriz
    if (linha >= 0 && linha < matriz.num_linhas && coluna >= 0 && coluna < matriz.num_colunas) {
        // Percorre a lista de valores na linha correspondente
        for (int i = matriz.ponteiros_linhas[linha]; i < matriz.valores.size(); i++) {
            // Se encontrar a coluna correspondente, retorna o valor
            if (matriz.colunas[i] == coluna) {
                return matriz.valores[i];
            }
            // Se a coluna for maior que a procurada, o elemento não está presente
            if (matriz.colunas[i] > coluna) {
                break;
            }
        }
    }
    // Se não encontrar o elemento, retorna 0 (valor padrão para elementos não nulos)
    return 0;
}

// Função para computar A^2 utilizando a matriz esparsa
MatrizEsparsa calcularA2(const MatrizEsparsa& A) {
    MatrizEsparsa A2;
    A2.num_linhas = A.num_linhas;
    A2.num_colunas = A.num_colunas;

    // Inicializa os ponteiros para as linhas da matriz A2
    A2.ponteiros_linhas.assign(A.num_linhas, 0);

    // Percorre cada elemento da matriz A e multiplica pela matriz A para calcular A^2
    for (int i = 0; i < A.num_linhas; i++) {
        for (int j = 0; j < A.num_colunas; j++) {
            // Calcula o elemento (i, j) da matriz A^2
            double valor_elemento = 0;
            for (int k = 0; k < A.num_colunas; k++) {
                valor_elemento += buscarElemento(A, i, k) * buscarElemento(A, k, j);
            }
            // Se o elemento não for zero, insere na matriz A2
            if (valor_elemento != 0) {
                inserirElemento(A2, i, j, valor_elemento);
            }
        }
    }

    return A2;
}

int main() {
    // Exemplo de criação de uma matriz esparsa 3x3
    MatrizEsparsa A;
    A.num_linhas = 3;
    A.num_colunas = 3;
    A.ponteiros_linhas.assign(3, 0); // Inicializa os ponteiros para as linhas

    // Inserindo alguns elementos não nulos na matriz A
    inserirElemento(A, 0, 0, 1);
    inserirElemento(A, 0, 2, 2);
    inserirElemento(A, 1, 1, 3);
    inserirElemento(A, 2, 0, 4);
    inserirElemento(A, 2, 2, 5);

    // Exemplo de busca de um elemento na matriz A
    cout << "Elemento (1, 1) da matriz A: " << buscarElemento(A, 1, 1) << endl;

    // Exemplo de cálculo da matriz A^2
    MatrizEsparsa A2 = calcularA2(A);

    return 0;
}
