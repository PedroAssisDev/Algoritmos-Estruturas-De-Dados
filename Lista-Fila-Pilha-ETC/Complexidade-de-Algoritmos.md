# Notações de Complexidade de Algoritmos

## Notação O (Grande O)

**Definição:** A notação $O$ descreve o limite superior do comportamento assintótico de uma função ou algoritmo. Em outras palavras, ela expressa o crescimento de uma função em termos de seu pior caso ou ordem de complexidade.

- **Complexidade do Pior Caso:** $\max_{E_i \in E} \{t_i\}$

**Exemplo:** Se um algoritmo de ordenação tem uma complexidade de $O(n^2)$, isso significa que o tempo de execução cresce no máximo proporcionalmente ao quadrado do tamanho da entrada.

**Fórmula Útil:** 
- Progressão Aritmética (PA): Soma dos $n$ primeiros termos: 

   $S_n = \frac{n}{2} \cdot (a_1 + a_n)$

## Notação Ω (Ômega)

**Definição:** A notação $\Omega$ descreve o limite inferior do comportamento assintótico de uma função ou algoritmo. Ela expressa o crescimento mínimo de uma função ou a ordem de complexidade no melhor caso.

- **Complexidade do Melhor Caso:** $\min_{E_i \in E} \{t_i\}$

**Exemplo:** Se um algoritmo de busca tem uma complexidade de $\Omega(\log n)$, isso significa que, no melhor caso, o tempo de execução cresce pelo menos logaritmicamente com o tamanho da entrada.

**Fórmula Útil:** 
- Progressão Geométrica (PG): Soma dos $n$ primeiros termos: 

   $S_n = a_1 \cdot \frac{1 - r^n}{1 - r}$

## Notação Θ (Theta) e Caso Médio

**Definição:** A notação $\Theta$ descreve o comportamento assintótico de uma função ou algoritmo quando o limite superior e o limite inferior são iguais. Em outras palavras, ela descreve o crescimento exato de uma função.

- **Complexidade do Caso Médio:** $\sum_{1 \leq i \leq m} p_i t_i$, onde $p_i$ é a probabilidade de ocorrência da entrada $E_i$.

**Explicação:** A análise de caso médio é uma abordagem para analisar o desempenho de algoritmos em relação a uma média ponderada de todas as entradas possíveis. É denotada como $\Theta$. A notação de caso médio oferece uma perspectiva sobre o desempenho esperado de um algoritmo ao longo de uma variedade de entradas, mas sua análise pode ser mais desafiadora e menos utilizada do que as análises de caso melhor e pior.
