#include <iostream>
using namespace std;

class Aluno
{
private:
    int ra;
    string nome;

public:
    // Construtores
    Aluno(); // Construtor padrão
    Aluno(int ra, string nome);

    // Métodos de acesso
    string getNome() const;
    int getRa() const;
};

// Implementação dos construtores
Aluno::Aluno()
{
    ra = -1;   // Valor padrão para RA não definido
    nome = ""; // Nome vazio por padrão
}

Aluno::Aluno(int ra, string nome)
{
    this->ra = ra;     // Define o RA do aluno
    this->nome = nome; // Define o nome do aluno
}

// Implementação dos métodos de acesso
string Aluno::getNome() const
{
    return nome; // Retorna o nome do aluno
}

int Aluno::getRa() const
{
    return ra; // Retorna o RA do aluno
}

class Hash
{
public:
    // Construtor e destrutor
    Hash(int max_itens = 100);
    ~Hash();

    // Métodos públicos
    bool isFull() const;
    int getLength() const;
    void retrieveItem(Aluno &aluno, bool &found);
    void insertItem(Aluno aluno);
    void deleteItem(Aluno aluno);
    void print();

private:
    // Métodos privados
    int getHash(Aluno aluno);

    // Variáveis de membro
    int max_itens;
    int length;
    Aluno *structure;
};

// Implementação do construtor
Hash::Hash(int max)
{
    length = 0;
    max_itens = max;
    structure = new Aluno[max_itens]; // Alocando memória para a estrutura de alunos
}

// Implementação do destrutor
Hash::~Hash()
{
    delete[] structure; // Liberando memória alocada para a estrutura de alunos
}

// Método para recuperar um item na tabela hash
void Hash::retrieveItem(Aluno &aluno, bool &found)
{
    int startLoc = getHash(aluno);
    bool moreToSearch = true;
    int location = startLoc;
    do
    {
        if (structure[location].getRa() == aluno.getRa() ||
            structure[location].getRa() == -1)
        {
            moreToSearch = false;
        }
        else
        {
            location = (location + 1) % max_itens;
        }
    } while (location != startLoc && moreToSearch);
    found = (structure[location].getRa() == aluno.getRa());
    if (found)
    {
        aluno = structure[location];
    }
}

// Método para inserir um item na tabela hash
void Hash::insertItem(Aluno aluno)
{
    int location = getHash(aluno);
    while (structure[location].getRa() > 0)
    {
        location = (location + 1) % max_itens;
    }
    structure[location] = aluno;
    length++;
}

// Método para excluir um item da tabela hash
void Hash::deleteItem(Aluno aluno)
{
    int startLoc = getHash(aluno);
    bool moreToSearch = true;
    int location = startLoc;
    do
    {
        if (structure[location].getRa() == aluno.getRa() ||
            structure[location].getRa() == -1)
        {
            moreToSearch = false;
        }
        else
        {
            location = (location + 1) % max_itens;
        }
    } while (location != startLoc && moreToSearch);

    if ((structure[location].getRa() == aluno.getRa()))
    {
        structure[location] = Aluno(-2, "");
        length--;
    }
}

// Função de hash simples para calcular a localização de um aluno na tabela
int Hash::getHash(Aluno aluno)
{
    cout << aluno.getRa() % max_itens << " " << aluno.getNome() << endl;
    return aluno.getRa() % max_itens; // Resto da divisão do RA pelo tamanho máximo da tabela
}

// Método para imprimir a tabela hash
void Hash::print()
{
    for (int i = 0; i < max_itens; i++)
    {
        cout << i << ": " << structure[i].getRa() << ", " << structure[i].getNome() << endl;
    }
}

int main()
{
    Hash alunosHash(10); // Criação de uma tabela hash com capacidade para 10 alunos

    int ras[7] = {
        12704, 31300, 1234,
        49001, 52202, 65606,
        91234};
    string nomes[7] = {
        "Pedro", "Raul", "Paulo",
        "Carlos", "Lucas", "Maria",
        "Samanta"};

    // Inserção dos alunos na tabela hash
    for (int i = 0; i < 7; i++)
    {
        Aluno aluno = Aluno(ras[i], nomes[i]);
        alunosHash.insertItem(aluno);
    }

    // Impressão da tabela hash
    cout << "Tabela hash após inserção:" << endl;
    alunosHash.print();
    cout << endl;

    // Recuperação de um aluno por RA
    int raBusca = 49001;
    Aluno alunoBusca;
    bool found = false;
    alunoBusca = Aluno(raBusca, ""); // Cria um objeto Aluno apenas com o RA
    alunosHash.retrieveItem(alunoBusca, found);
    if (found)
    {
        cout << "Aluno encontrado: " << alunoBusca.getNome() << endl;
    }
    else
    {
        cout << "Aluno com RA " << raBusca << " não encontrado." << endl;
    }
    cout << endl;

    // Exclusão de um aluno por RA
    int raExclusao = 65606;
    Aluno alunoExclusao(raExclusao, ""); // Cria um objeto Aluno apenas com o RA
    alunosHash.deleteItem(alunoExclusao);
    cout << "Após exclusão do aluno com RA " << raExclusao << ":" << endl;
    alunosHash.print();
    cout << endl;

    // Verificação se um aluno está na tabela
    int raVerificacao = 31300;
    Aluno alunoVerificacao(raVerificacao, ""); // Cria um objeto Aluno apenas com o RA
    found = false;
    alunosHash.retrieveItem(alunoVerificacao, found);
    if (found)
    {
        cout << "Aluno com RA " << raVerificacao << " está na tabela." << endl;
    }
    else
    {
        cout << "Aluno com RA " << raVerificacao << " não está na tabela." << endl;
    }
    cout << endl;
    alunosHash.print();

    return 0;
}
