#include <iostream>
#include <stack>
#include <string>

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para converter uma expressão da notação parentizada para a notação polonesa reversa
std::string convertToPostfix(const std::string& expression) {
    std::string postfix; // Expressão na notação polonesa reversa
    std::stack<char> operatorStack; // Pilha para armazenar os operadores

    // Iterar sobre cada caractere da expressão
    for (char c : expression) {
        // Se o caractere for um operando, adicioná-lo à expressão polonesa reversa
        if (isalnum(c)) {
            postfix += c;
        }
        // Se o caractere for um operador
        else if (isOperator(c)) {
            // Empilhar operadores na pilha
            while (!operatorStack.empty() && operatorStack.top() != '(' && (c != '*' && c != '/') &&
                   ((c == '+' || c == '-') && (operatorStack.top() == '*' || operatorStack.top() == '/'))) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c); // Empilhar o operador atual na pilha
        }
        // Se o caractere for um parêntese de abertura
        else if (c == '(') {
            operatorStack.push(c); // Empilhar o parêntese na pilha
        }
        // Se o caractere for um parêntese de fechamento
        else if (c == ')') {
            // Desempilhar operadores e adicioná-los à expressão polonesa reversa até encontrar o parêntese de abertura
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Remover o parêntese de abertura da pilha
        }
    }

    // Desempilhar operadores restantes e adicioná-los à expressão polonesa reversa
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    // Expressão na notação parentizada
    std::string expression = "((A * B) - (C / D))";

    // Converter para a notação polonesa reversa
    std::string postfixExpression = convertToPostfix(expression);

    // Imprimir a expressão na notação polonesa reversa
    std::cout << "Expressao na notacao polonesa reversa: " << postfixExpression << std::endl;

    return 0;
}
