# Perguntas e Respostas sobre Procedimentos Recursivos

## Pergunta 1.1
Responder se é certo ou errado: Todo procedimento recursivo deve incorporar terminações sem chamadas recursivas, caso contrário ele seria executado um número infinito de vezes.

**Resposta:** Errado. Por exemplo, consideremos o cálculo do fatorial de um número de forma recursiva. No algoritmo recursivo, a recursão é encerrada quando o valor do número é menor ou igual a 1, o que impede a execução infinita.

## Pergunta 1.2
Responder se é certa ou errada cada afirmativa abaixo:
- O Algoritmo 1.2, que calcula o fatorial de forma recursiva, requer apenas uma quantidade constante de memória.
- O Algoritmo 1.3, fatorial não recursivo, requer o armazenamento do vetor fat, com n + 1 elementos.

**Resposta para Algoritmo 1.2:** Errada. No cálculo do fatorial de forma recursiva, cada chamada recursiva adiciona uma entrada à pilha de chamadas, consumindo espaço na memória proporcional ao número de chamadas recursivas. Portanto, a quantidade de memória necessária não é constante.

**Resposta para Algoritmo 1.3:** Certa. No cálculo do fatorial de forma não recursiva, utilizamos um vetor `fat` com `n + 1` elementos para armazenar os resultados intermediários. Cada elemento do vetor ocupa um espaço constante na memória. Portanto, o espaço de memória necessário para armazenar o vetor é linear em relação ao valor de entrada `n`.


## Pergunta 1.3
Desenvolver um algoritmo não recursivo para o cálculo do fatorial de inteiro $n \geq 0$, de tal forma que prescinda do armazenamento de qualquer vetor.

**Resposta:** Podemos calcular o fatorial de forma não recursiva utilizando um loop para multiplicar todos os números de 1 até $n$. Não é necessário armazenar nenhum vetor. Aqui está um exemplo de algoritmo não recursivo para calcular o fatorial de $n$ em C++:

```cpp
#include <iostream>

int calcularFatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int n = 5; // Exemplo de valor para n
    std::cout << "O fatorial de " << n << " é: " << calcularFatorial(n) << std::endl;
    return 0;
}
```

## Pergunta 1.4
Mostrar que o Algoritmo 1.4, para o problema da Torre de Hanói, requer exatamente $2^n - 1$ movimentos de disco para terminar.

**Resposta:** O problema da Torre de Hanói é bem conhecido por sua solução recursiva. Podemos demonstrar que o número mínimo de movimentos necessários para resolver o problema com $n$ discos é dado pela fórmula $2^n - 1$.

Usando a linguagem C++, podemos implementar uma função recursiva para resolver a Torre de Hanói e contar o número de movimentos realizados. Aqui está um exemplo de implementação:

```cpp
#include <iostream>

void torreDeHanoi(int n, char origem, char destino, char auxiliar, int& movimentos) {
    if (n == 1) {
        ++movimentos;
        std::cout << "Mover disco de " << origem << " para " << destino << std::endl;
        return;
    }

    torreDeHanoi(n - 1, origem, auxiliar, destino, movimentos);
    ++movimentos;
    std::cout << "Mover disco de " << origem << " para " << destino << std::endl;
    torreDeHanoi(n - 1, auxiliar, destino, origem, movimentos);
}

int main() {
    int n = 3; // Exemplo de número de discos
    int movimentos = 0;
    torreDeHanoi(n, 'A', 'C', 'B', movimentos);
    std::cout << "Número total de movimentos: " << movimentos << std::endl;
    return 0;
}
```
Este programa calcula o número total de movimentos necessários para resolver o problema da Torre de Hanói com $n$ discos. Ao executar o programa, podemos verificar que o número de movimentos é de fato $2^n - 1$ para um determinado valor de $n$.


## Pergunta 1.14
Escrever as seguintes funções em notação O:
1. $n^3 - 1$
   - Notação O: $O(n^3)$

2. $n^2 + 2 \log n$
   - Notação O: $O(n^2)$

3. $3n^n + 5 \cdot 2^n$
   - Notação O: $O(n^n)$

4. $(n - 1)n^{n-1} + n^{n-1}$
   - Notação O: $O(n^n)$

5. $30^2$
   - Notação O: $O(1)$


## Pergunta 1.15
Responder se é certo ou errado: Se $f$, $g$ são funções tais que $f = O(g)$ e $g = \Omega(f)$, então $f = \Theta(g)$.

**Resposta:** Errado. De acordo com a definição formal da notação assintótica, se $f = O(g)$ e $g = \Omega(f)$, então $f = \Theta(g)$. Isso significa que $f$ e $g$ têm o mesmo comportamento assintótico, ou seja, $f$ cresce (ou decresce) tão rapidamente quanto $g$. Portanto, a afirmação de que $f = \Theta(g)$ é verdadeira quando $f = O(g)$ e $g = \Omega(f)$.


## Pergunta 1.16
Responder se é certo ou errado: A definição da notação $\Theta$, dada na Seção 1.5, é equivalente à seguinte: sejam $f$, $h$ funções reais positivas da variável inteira $n$. Diz-se que $f = \Theta(h)$ quando existirem constantes $c$, $d > 0$ e um valor inteiro $n_0$, tal que $n > n_0 \Rightarrow c \cdot h(n) \leq f(n) \leq d \cdot h(n)$.

**Resposta:** Certo. Essa é a definição correta da notação $\Theta$.

## Pergunta 1.17
Responder se é certo ou errado: Se a complexidade de melhor caso de um algoritmo for $f$, então o número de passos que o algoritmo efetua, qualquer que seja a entrada, é $\Omega(f)$.

**Resposta:** Errado. A complexidade de melhor caso não implica necessariamente um limite inferior para o número de passos que o algoritmo efetua.

## Pergunta 1.18
Responder se é certo ou errado: Se a complexidade de pior caso de um algoritmo for $f$, então o número de passos que o algoritmo efetua, qualquer que seja a entrada, é $\Theta(f)$.

**Resposta:** Errado. A complexidade de pior caso implica um limite superior, mas não necessariamente um limite inferior.

## Pergunta 1.19
Responder se é certo ou errado: A complexidade de melhor caso de um algoritmo para um certo problema é necessariamente maior do que qualquer limite inferior para o problema.

**Resposta:** Errado. A complexidade de melhor caso pode ser menor do que alguns limites inferiores, dependendo da análise do problema.

## Pergunta 1.20
A sequência de Fibonacci é uma sequência de elementos $f_1, \ldots, f_n$, definida do seguinte modo:
- $f_1 = 0$
- $f_2 = 1$
- $f_j = f_{j-1} + f_{j-2}$, para $j > 2$.

Elaborar um algoritmo, não recursivo, para determinar o elemento $f_n$ da sequência, cuja complexidade seja linear em $n$.

**Resposta:**
Para determinar o elemento $f_n$ da sequência de Fibonacci de forma não recursiva e com complexidade linear em $n$, podemos usar um algoritmo iterativo que calcula os termos da sequência até alcançar o termo desejado. Aqui está um exemplo de implementação em C++:

```cpp
#include <iostream>

int fibonacci(int n) {
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = b;
        b += a;
        a = temp;
    }
    return b;
}

int main() {
    int n = 10; // Exemplo: encontrar o 10º termo da sequência de Fibonacci
    std::cout << "O " << n << "º termo da sequência de Fibonacci é: " << fibonacci(n) << std::endl;
    return 0;
}
```
Este algoritmo calcula o $n$-ésimo termo da sequência de Fibonacci de forma iterativa, evitando a sobrecarga causada pela recursão.

## Pergunta 1.21

Determinar a expressão do elemento $f_n$ da sequência de Fibonacci em termos de $n$.

**Resposta:**

A expressão do $n$-ésimo termo da sequência de Fibonacci em termos de $n$ pode ser encontrada usando a fórmula de Binet, que é dada por:

$$
f_n = \frac{1}{\sqrt{5}} \left( \left( \frac{1 + \sqrt{5}}{2} \right)^n - \left( \frac{1 - \sqrt{5}}{2} \right)^n \right)
$$

Essa fórmula fornece uma expressão direta para o $n$-ésimo termo da sequência de Fibonacci, sem a necessidade de calcular todos os termos anteriores.


## Pergunta 1.22
Determinar o número de chamadas recursivas e a complexidade do seguinte algoritmo, para determinar o elemento $f_n$ da sequência de Fibonacci:

```cpp
função f(n)
    se n = 1 então
        retornar 0
    senão se n = 2 então
        retornar 1
    senão
        retornar f(n - 1) + f(n - 2)
```

**Resposta:**

Este algoritmo para determinar o $n$-ésimo termo da sequência de Fibonacci é implementado de forma recursiva. A complexidade de tempo deste algoritmo é exponencial, devido ao grande número de chamadas recursivas que são feitas.

O número de chamadas recursivas pode ser calculado observando que cada chamada recursiva resulta em duas chamadas adicionais (uma para $f(n-1)$ e outra para $f(n-2)$), exceto para os casos bases $n = 1$ e $n = 2$. Portanto, o número total de chamadas recursivas é da ordem de $2^n$, o que contribui para a complexidade exponencial do algoritmo.