#include <iostream>
#include <map>
#include <iterator>

//Classe Teste
class Teste
{

public:
    Teste() : value(10), nome("Azul")
    {

    }

    ~Teste();

    int value;
    std::string nome;

};

//Definindo destrutor da classe Teste
Teste::
~Teste()
{
    std::cout << "Objeto destruido" << std::endl;
}

//struct DOIDERA herdando std::map e a classe Teste
struct DOIDERA : std::map<std::string, int>, Teste
{
    float mexerica;

    void setValue(float val)
    {
        mexerica = val;
    }

    float getValue()
    {
        return mexerica;
    }

};

//instanciando iterator para a struct DOIDERA
DOIDERA::iterator itD;

int main()
{

    //Declarando a struct DOIDERA
    DOIDERA d;

    //Chamando valores definidas e instanciadas na classe, Teste herdada na struct DOIDERA
    std::cout << d.value << " " << d.nome << std::endl << std::endl;

    //Dando valores de map para o objeto
    d.insert(std::pair<std::string, int>("Abacate", 1));
    d.insert(std::pair<std::string, int>("Moises", 2));
    d.insert(std::pair<std::string, int>("Ronaldo", 3));
    d.insert(std::pair<std::string, int>("Abobra", 3));
    d.insert(std::pair<std::string, int>("Dinamarca", 5));

    //printando valores criados
    std::cout << "Printando valores\n";
    for(itD = d.begin(); itD != d.end(); itD++)
    {
        std::cout << itD->first << " | " << itD->second << std::endl;
    }

    //setando valor com o método da struct DOIDERA
    d.setValue(7);

    //printando valor com o método da struct DOIDERA
    std::cout << d.getValue() << std::endl;

    //procurando o iterator de key 'Ronaldo'
    itD = d.find("Ronaldo");

    //printando valores de find
    std::cout << "Aplicando find: " << itD->first << " | " << itD->second << std::endl << std::endl;

    //excluindo valor por iterator
    d.erase(itD);

    return 0;
}
