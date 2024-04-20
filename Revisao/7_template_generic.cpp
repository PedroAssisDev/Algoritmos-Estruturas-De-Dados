#include <cstdio>

// Função genérica usando template para calcular a soma de dois valores
template <typename T>
T soma(T a, T b) {
    return a + b;
}

// Classe genérica usando template para armazenar um valor
template <typename T>
class Caixa {
private:
    T conteudo; // Conteúdo da caixa

public:
    // Construtor da classe Caixa
    Caixa(T valor) : conteudo(valor) {}

    // Método para obter o conteúdo da caixa
    T obterConteudo() {
        return conteudo;
    }
};

// Especialização de modelo para o tipo int
template <>
class Caixa<int> {
private:
    int conteudo; // Conteúdo da caixa de tipo int

public:
    // Construtor da classe Caixa especializada para int
    Caixa(int valor) : conteudo(valor) {}

    // Método para obter o conteúdo da caixa (multiplicado por 2)
    int obterConteudo() {
        return conteudo * 2; // Especialização: multiplica por 2 para inteiros
    }
};

int main() {
    // Exemplos de uso da função genérica soma com inteiros e floats
    int int1 = 5, int2 = 3;
    printf("Soma de inteiros: %d\n", soma(int1, int2));

    float float1 = 3.5, float2 = 2.5;
    printf("Soma de floats: %.2f\n", soma(float1, float2));

    // Exemplos de uso da classe genérica Caixa com diferentes tipos
    Caixa<int> caixaInt(10);
    printf("Conteúdo da caixa (int): %d\n", caixaInt.obterConteudo());

    Caixa<float> caixaFloat(7.5);
    printf("Conteúdo da caixa (float): %.2f\n", caixaFloat.obterConteudo());

    return 0;
}
