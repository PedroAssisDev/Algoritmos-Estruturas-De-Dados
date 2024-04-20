#include <iostream>  // Inclui a biblioteca iostream para usar std::cout
#include <vector>    // Inclui a biblioteca vector para usar estrutura de dados

int main() {
    // Tipos de dados
    int inteiro = 10;               // Declara e inicializa um inteiro
    float ponto_flutuante = 3.14;   // Declara e inicializa um ponto flutuante
    char caractere = 'A';           // Declara e inicializa um caractere
    bool booleano = true;           // Declara e inicializa um booleano

    // Variáveis e Constantes
    int variavel = 20;              // Declara e inicializa uma variável

    // const é uma palavra-chave em C++ que indica que uma variável é uma constante, ou seja, seu valor não pode ser alterado após a inicialização.
    const int constante = 100;      // Declara e inicializa uma constante usando const

    // Escopo e Modificadores de Tipo
    int global = 10;                // Declara e inicializa uma variável global
    {
        int local = 20;             // Declara e inicializa uma variável local dentro de um escopo
        std::cout <<"Variável global: " << global << "\n";
        std::cout << "Variável local: " << local << "\n";
    }

    // Operadores
    int a = 10, b = 5;
    std::cout << "Soma: " << a + b << "\n";
    std::cout << "Subtração: " << a - b << "\n";
    std::cout << "Multiplicação: " << a * b << "\n";
    std::cout << "Divisão: " << a / b << "\n";
    std::cout << "Módulo: " << a % b << "\n";

    // Estruturas de Controle
    int numero = 10;
    if (numero > 0) {
        std::cout << "Número positivo\n";
    } else {
        std::cout << "Número negativo ou zero\n";
    }

    int opcao = 2;
    switch (opcao) {
        case 1:
            std::cout << "Opção 1 selecionada\n";
            break;
        case 2:
            std::cout << "Opção 2 selecionada\n";
            break;
        default:
            std::cout << "Opção inválida\n";
            break;
    }

    // Loops
    std::cout << "Loop 'for':\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Valor de i: " << i << "\n";
    }

    std::cout << "Loop 'while':\n";
    int j = 0;
    while (j < 5) {
        std::cout << "Valor de j: " << j << "\n";
        ++j;
    }

    std::cout << "Loop 'do-while':\n";
    int k = 0;
    do {
        std::cout << "Valor de k: " << k << "\n";
        ++k;
    } while (k < 5);

    // while: Avalia a condição antes de executar o bloco de código.
    // do-while: Executa o bloco de código pelo menos uma vez e depois avalia a condição.
    std::cout << "Comparação 'do-while' e 'while':\n";
    std::cout << "Loop 'do-while' k = 5 e while (k < 5):\n";
    k = 5;
    do {
        std::cout << "Printa valor do while pois executa o bloco de código pelo menos uma vez e depois avalia a condição. : " << k << "\n";
        ++k;
    } while (k < 5);
    std::cout << "Loop 'while' k = 5 e while (k < 5):\n";
    k = 5;
    while (k < 5) {
        std::cout << "Valor de j: " << k << "\n";
        ++k;
    }
    std::cout << "Não entra dentro do 'while' pois avalia a condição antes de executar o bloco de código.:\n";
    std::cout << "Fim Comparação 'do-while' e 'while':\n";

    // Arrays
    int numeros[5] = {10, 20, 30, 40, 50};
    std::cout << "Array:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Número " << i + 1 << ": " << numeros[i] << "\n";
    }

    // Estruturas de Dados
    std::vector<int> vetor = {1, 2, 3, 4, 5}; // Cria um vetor de inteiros
    std::cout << "Estrutura de Dados 'vector':\n";
    for (int numero : vetor) {
        std::cout << "Número: " << numero << "\n";
    }

    // int numeros[5]: Este é um array estático que armazena um conjunto fixo de elementos do tipo int. O tamanho do array é definido em tempo de compilação e não pode ser alterado durante a execução do programa.

    // std::vector<int> vetor: Este é um vetor dinâmico da biblioteca padrão do C++. Ele pode crescer ou diminuir dinamicamente em tamanho durante a execução do programa. Além disso, fornece funções e métodos convenientes para manipulação de elementos, como adição, remoção e acesso a elementos. Ele é uma estrutura de dados mais flexível em comparação com os arrays estáticos, pois permite fácil modificação do tamanho e outras operações de vetor.

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
