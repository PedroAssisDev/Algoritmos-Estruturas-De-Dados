# Filas de Prioridade e Árvores Binárias

As filas de prioridade são estruturas de dados que mantêm uma coleção de elementos, cada um associado a uma prioridade. Os elementos com maior prioridade são atendidos antes dos elementos com menor prioridade, seguindo a lógica de uma fila. Duas implementações comuns de filas de prioridade são baseadas em árvores binárias: heap binário e heap binomial.

## Heap Binário

Um heap binário é uma árvore binária completa em que cada nó possui uma chave maior ou igual à chave de seus filhos (no caso de um heap máximo) ou menor ou igual à chave de seus filhos (no caso de um heap mínimo). Isso garante que o elemento com a maior prioridade (ou menor, dependendo do tipo de heap) esteja sempre na raiz da árvore.

### Operações Principais em Heap Binário

- **Inserção:** Insere um novo elemento na fila de prioridade, mantendo a propriedade do heap.
- **Remoção:** Remove o elemento de maior prioridade da fila de prioridade, reorganizando o heap conforme necessário.
- **Construção:** Constrói um heap binário a partir de uma coleção de elementos, garantindo que a propriedade do heap seja preservada.

### Complexidade de Tempo em Heap Binário

As operações principais em um heap binário têm as seguintes complexidades de tempo no pior caso:

- Inserção: O(log n)
- Remoção: O(log n)
- Construção: O(n)

## Heap Binomial

Um heap binomial é uma coleção de árvores binomiais, onde cada árvore binomial segue as propriedades de um heap mínimo. Uma árvore binomial de ordem k possui 2^k nós e é definida de forma recursiva.

### Operações Principais em Heap Binomial

- **Inserção:** Insere um novo elemento na fila de prioridade, combinando dois heaps binomiais se necessário.
- **Remoção:** Remove o elemento de menor prioridade da fila de prioridade, reorganizando os heaps binomiais conforme necessário.
- **União:** Combina duas filas de prioridade em uma única fila de prioridade, mantendo a propriedade do heap binomial.

### Complexidade de Tempo em Heap Binomial

As operações principais em um heap binomial têm as seguintes complexidades de tempo no pior caso:

- Inserção: O(log n)
- Remoção: O(log n)
- União: O(log n)

## Comparação entre Heap Binário e Heap Binomial

Ambos os heaps binário e binomial são estruturas eficientes para implementar filas de prioridade. A escolha entre eles depende das características específicas do problema em questão. Em geral, o heap binomial tende a ser mais eficiente para operações de união de filas de prioridade, enquanto o heap binário pode ser mais simples de implementar e mais eficiente para operações de inserção e remoção individuais.

