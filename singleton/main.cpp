//https://pt.wikipedia.org/wiki/Singleton
//-fpermissive flag activated
//https://pt.stackoverflow.com/questions/482918
#include <iostream>

class Base{

private:
    //meu objeto único estático
    static Base* _obj;

    //construtor em private para que não seja possível acessar de fora da classe
    Base()
    {
        std::cout << "Fui criado!\n";
    }

public:

    //teste
    void falar()
    {
        std::cout << "Alo!\n";
    }

    //getHandle retorna o _obj se estiver instanciado
    //se não, inicia o objeto
    static Base* getBase()
    {
        if(!_obj)
            _obj = new Base;

        return _obj;
    }
};

//inicializa como nullptr
Base* Base::_obj = nullptr;

int main()
{
    //mãos a obra!
    Base::getBase()->falar();

    return 0;

}

