#include <iostream>

class Base{

public:
    int* num;

    int* criaNum()
    {
        num = new int(2);

        return num;

    }

    int* num2;

    void setaNum()
    {
        num2 = criaNum();
    }

    void printa()
    {
        std::cout << *num2;
    }



};


int main()
{
    Base b;

    b.criaNum();

    b.setaNum();

    b.printa();

    return 0;
}
