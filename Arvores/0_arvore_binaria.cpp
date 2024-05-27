#include <iostream>
using namespace std;

class Aluno
{
private:
    int ra;
    string nome;

public:
    Aluno(int ra, string nome);
    Aluno();
    string getNome() const;
    int getRa() const;
};

Aluno::Aluno(int ra, string nome)
{
    this->ra = ra;
    this->nome = nome;
}

Aluno::Aluno()
{
    this->ra = -1;
    this->nome = "";
}

string Aluno::getNome() const
{
    return nome;
}
int Aluno::getRa() const
{
    return ra;
}

struct NoArvore
{
    Aluno aluno;
    NoArvore *esquerda;
    NoArvore *direita;
};

class SearchTree
{
private:
    void destroyTree(NoArvore *&tree);
    void retriveAluno(NoArvore *&tree, Aluno &item, bool &found);
    void insertAluno(NoArvore *&tree, Aluno item);
    void deleteAluno(NoArvore *&tree, Aluno item);
    void deleteNode(NoArvore *&tree);
    void getSucessor(NoArvore *tree, Aluno item);
    void printTree(NoArvore *tree);
    void printPreOrder(NoArvore *tree);
    void printInOrder(NoArvore *tree);
    void printPostOrder(NoArvore *tree);
    NoArvore *root;

public:
    SearchTree() { root = NULL; };
    ~SearchTree() { destroyTree(root); };
    bool isEmpty();
    bool isFull();
    void retriveAluno(Aluno &item, bool &found)
    {
        retriveAluno(root, item, found);
    }
    void insertAluno(Aluno item)
    {
        insertAluno(root, item);
    }
    void deleteAluno(int item)
    {
        //deleteAluno(root, item);
    }
    void printPreOrder()
    {
        printPreOrder(root);
    }
    void printInOrder()
    {
        printInOrder(root);
    }
    void printPostOrder()
    {
        printPostOrder(root);
    }
};

void SearchTree::destroyTree(NoArvore *&tree)
{
    if (tree != NULL)
    {
        destroyTree(tree->esquerda);
        destroyTree(tree->direita);
        delete tree;
    }
}

bool SearchTree::isEmpty()
{
    return root == NULL;
}

bool SearchTree::isFull()
{
    NoArvore *location;
    try
    {
        location = new NoArvore;
        delete location;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

void SearchTree::retriveAluno(NoArvore *&tree, Aluno &aluno, bool &found)
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (aluno.getRa() < tree->aluno.getRa())
    {
        retriveAluno(tree->esquerda, aluno, found);
    }
    else if (aluno.getRa() > tree->aluno.getRa())
    {
        retriveAluno(tree->direita, aluno, found);
    }
    else
    {
        aluno = tree->aluno;
        found = true;
    }
}

void SearchTree::insertAluno(NoArvore *&tree, Aluno item)
{
    if (tree == NULL){
        tree = new NoArvore;
        tree->direita = NULL;
        tree->esquerda = NULL;
        tree->aluno = item;
    }
    else if (item.getRa() < tree->aluno.getRa()){
        insertAluno(tree->esquerda, item);

    }else if (item.getRa() > tree->aluno.getRa()){
            insertAluno(tree->direita, item);
    }
}

void SearchTree::printPreOrder(NoArvore *tree){
    if(tree != NULL){
        cout << tree->aluno.getNome() <<" , ";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
}
void SearchTree::printInOrder(NoArvore *tree){
    if(tree != NULL){
        printPreOrder(tree->esquerda);
        cout << tree->aluno.getNome() <<" , ";
        printPreOrder(tree->direita);
    }
}
void SearchTree::printPostOrder(NoArvore *tree){
    if(tree != NULL){
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
        cout << tree->aluno.getNome() <<" , ";
    }
}


int main()
{
    // Criando uma árvore de busca.
    SearchTree tree;

    // Verificando se a árvore está vazia.
    if (tree.isEmpty())
    {
        cout << "A árvore está vazia." << endl;
    }

    // Inserindo alunos na árvore.
    tree.insertAluno(Aluno(123, "João"));
    tree.insertAluno(Aluno(456, "Maria"));
    tree.insertAluno(Aluno(789, "José"));

    // Imprimindo a árvore em diferentes ordens.
    cout << "Impressão PreOrder: ";
    tree.printPreOrder();
    cout << endl;

    cout << "Impressão InOrder: ";
    tree.printInOrder();
    cout << endl;

    cout << "Impressão PostOrder: ";
    tree.printPostOrder();
    cout << endl;

    // Buscando um aluno na árvore.
    Aluno aluno(456, ""); // RA do aluno que queremos buscar.
    bool found;
    tree.retriveAluno(aluno, found);
    if (found)
    {
        cout << "Aluno encontrado: " << aluno.getNome() << endl;
    }
    else
    {
        cout << "Aluno não encontrado." << endl;
    }

    // Deletando um aluno da árvore.
    tree.deleteAluno(456);
    cout << "Impressão InOrder após deletar Maria: ";
    tree.printInOrder();
    cout << endl;

    return 0;
}
