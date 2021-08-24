#include <iostream>
#include <tgmath.h>

//visto no livro "Entendendo algoritmos", pág. 60 de Aditya Y. Bhargava - ISBN 978-85-7522-563-9

using namespace std;

int casoBase(int X, int Y)
{
    float menorNum, maiorNum, aux, res;

    if(X > Y)
    {
        maiorNum = (float)X;
        menorNum = (float)Y;
    }
    else
    {
        maiorNum = (float)Y;
        menorNum = (float)X;
    }

    res = maiorNum / menorNum;

    if(floor(res) == res)
        return (int)menorNum;
    else
    {
        //sobra menor
        aux = maiorNum - (floor(res) * menorNum);
        casoBase(aux, menorNum);

    }

}

int main()
{

	int valX = 1960;
	int valY = 1280;
	
    cout << "O caso base de " << valX << "x" << valY << " e " << casoBase(valX, valY) << endl;

    return 0;
}

