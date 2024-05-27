#include <iostream>
using namespace std;
#include <stack>
#include <queue>

struct NoArvore
{
    int chave;
    NoArvore *esquerda, *direita;
};

void insert(NoArvore *&raiz, int valor)
{
    if (raiz == NULL)
    {
        raiz = new NoArvore;
        raiz->direita = NULL;
        raiz->esquerda = NULL;
        raiz->chave = valor;
    }
    else if (valor < raiz->chave)
    {
        insert(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave)
    {
        insert(raiz->direita, valor);
    }
}

bool busca(NoArvore *raiz, int valor)
{
    if (raiz == NULL)
    {
        return false;
    }
    else if (valor < raiz->chave)
    {
        busca(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave)
    {
        busca(raiz->direita, valor);
    }
    else if (valor == raiz->chave)
    {
        return true;
    }
}

int buscaMaior(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        throw std::invalid_argument("A árvore está vazia");
    }
    NoArvore *atual = raiz;
    while (atual->direita != NULL)
    {
        atual = atual->direita;
    }
    return atual->chave;
}

int buscaMenor(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        throw std::invalid_argument("A árvore está vazia");
    }
    NoArvore *atual = raiz;
    while (atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual->chave;
}

int contaValor(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + contaValor(raiz->direita) + contaValor(raiz->esquerda);
}

int contaMaior(NoArvore *raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int count = 0;
    if (raiz->chave > valor)
    {
        count = 1;
    }
    return count + contaMaior(raiz->direita, valor) + contaMaior(raiz->esquerda, valor);
}
int contaMenor(NoArvore *raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int count = 0;
    if (raiz->chave < valor)
    {
        count = 1;
    }
    return count + contaMenor(raiz->direita, valor) + contaMenor(raiz->esquerda, valor);
}

int alturaNo(NoArvore *no)
{
    if (no == NULL)
    {
        return 0;
    }
    else
    {
        int alturaEsquerda = alturaNo(no->esquerda);
        int alturaDireita = alturaNo(no->direita);
        return max(alturaEsquerda, alturaDireita) + 1;
    }
}

void imprimirArvore(NoArvore *raiz, int espaco = 0, int distancia = 5)
{
    if (raiz == NULL)
        return;

    espaco += distancia;

    // Imprimir subárvore direita primeiro
    imprimirArvore(raiz->direita, espaco);

    // Imprimir o nó atual depois de espaços
    cout << endl;
    for (int i = distancia; i < espaco; i++)
        cout << " ";
    cout << raiz->chave << "\n";

    // Imprimir subárvore esquerda
    imprimirArvore(raiz->esquerda, espaco);
}

void percursopre(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->chave << ", ";
        percursopre(raiz->esquerda);
        percursopre(raiz->direita);
    }
}
void percursoin(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        percursoin(raiz->esquerda);
        cout << raiz->chave << ", ";
        percursoin(raiz->direita);
    }
}
void percursopos(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        percursopos(raiz->esquerda);
        percursopos(raiz->direita);
        cout << raiz->chave << ", ";
    }
}

void percursoPre(NoArvore *raiz)
{
    std::stack<NoArvore *> pilha;
    NoArvore *p = raiz;
    while (p != NULL || !pilha.empty())
    {
        if (p != NULL)
        {
            pilha.push(p);
            std::cout << p->chave << ", ";
            p = p->esquerda;
        }
        else
        {
            p = pilha.top();
            pilha.pop();
            p = p->direita;
        }
    }
}

void percursoIn(NoArvore *raiz)
{
    std::stack<NoArvore *> pilha;
    NoArvore *p = raiz;

    while (p != NULL || !pilha.empty())
    {
        if (p != NULL)
        {
            pilha.push(p);
            p = p->esquerda;
        }
        else
        {
            p = pilha.top();
            pilha.pop();
            std::cout << p->chave << ", ";
            p = p->direita;
        }
    }
}

void percursoPos(NoArvore *raiz)
{
    std::stack<NoArvore *> pilha;
    NoArvore *p = raiz;

    while (p != NULL || !pilha.empty())
    {
        if (p != NULL)
        {
            pilha.push(p);
            p = p->esquerda;
            std::cout << p->chave << ", ";
        }
        else
        {
            p = pilha.top();
            pilha.pop();
            p = p->direita;
        }
    }
}

void bfs(NoArvore *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }

    std::queue<NoArvore *> fila;
    fila.push(raiz);

    while (!fila.empty())
    {
        NoArvore *atual = fila.front();
        fila.pop();

        std::cout << atual->chave << ", ";

        if (atual->esquerda)
        {
            fila.push(atual->esquerda);
        }
        if (atual->direita)
        {
            fila.push(atual->direita);
        }
    }
}

int numeroNos(NoArvore* raiz){
    if (raiz == NULL){
        return 0;
    }
    return 1 + numeroNos(raiz->esquerda) + numeroNos(raiz->direita);
}

int main()
{
    NoArvore *raiz = NULL;

    insert(raiz, 6);
    insert(raiz, 4);
    insert(raiz, 2);
    insert(raiz, 1);
    insert(raiz, 3);
    insert(raiz, 10);
    insert(raiz, 88);
    insert(raiz, 8);
    insert(raiz, 7);
    insert(raiz, 9);
    cout << "A arvore  tem :" << (numeroNos(raiz)) << " nós \n";
    cout << "Percurso Pre-Ordem: " << endl;
    percursopre(raiz);
    cout << endl;
    cout << "Percurso Pre-Ordem: " << endl;
    percursoPre(raiz);
    cout << endl;
    cout << "Percurso In-Ordem: " << endl;
    (percursoin(raiz));
    cout << endl;
    cout << "Percurso In-Ordem: " << endl;
    (percursoIn(raiz));
    cout << endl;
    cout << "Percurso Pos-Ordem: " << endl;
    (percursopos(raiz));
    cout << endl;

    std::cout << "Busca em largura (BFS): ";
    bfs(raiz);
    std::cout << std::endl;

    cout << "A altura da arvore é:" << (alturaNo(raiz)) << "\n";
    cout << "O maior valor da arvore é:" << (buscaMaior(raiz)) << "\n";
    cout << "O menor valor da arvore é:" << (buscaMenor(raiz)) << "\n";
    cout << "O valor 2  existe ?" << (busca(raiz, 2) ? "true" : "false") << "\n";
    cout << "O valor 99 existe ?" << (busca(raiz, 99) ? "true" : "false") << "\n";
    cout << "Existe " << contaValor(raiz) << " valores na arvore\n";
    cout << "Existe " << contaMaior(raiz, 5) << " valores maior que 5\n";
    cout << "Existe " << contaMaior(raiz, 99) << " valores maior que 99\n";
    cout << "Existe " << contaMenor(raiz, 5) << " valores menor que 5\n";
    cout << "Existe " << contaMenor(raiz, 99) << " valores menor que 99\n";
    imprimirArvore(raiz);
}