#include <iostream>
#include <time.h>
#include <stdlib.h>

#define TOTAL 10000
#define MAX_VAL 10000

using namespace std;

bool Existe(int valores[], int tam, int valor)
{
    for(int i = 0; i < tam; i++)
    {
        if(valores[i] == valor)
            return true;
    }
    return false;

}
void GeraAleatorios(int numeros[], int quantNumeros, int Limite)
{
    srand(time(NULL));

    int v;
    for(int i = 0; i < quantNumeros; i++)
    {
        v = rand() % Limite;
        while(Existe(numeros, i, v))
            v = rand() % Limite;

        numeros[i] = v;
    }
}

int main()
{
    int numeros[TOTAL];
    GeraAleatorios(numeros, TOTAL, MAX_VAL);

    for(int i = 0; i < TOTAL; i++)
    {
        cout << numeros[i] << endl;
    }

    cout << "Hello World!" << endl;

    return 0;

}
