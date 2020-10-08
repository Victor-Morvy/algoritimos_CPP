#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>

using namespace std;

class Carro{
public:
    Carro(int id, int algo)
    {
        this->id = id;
        this->algo = algo;
    }

    ~Carro()
    {
        cout << "OBJ CARRO DESTRUIDO\n";

    }

    int getId()
    {
        return this->id;
    }

    int getAlgo()
    {
        return this->algo;
    }

private:
    int id;
    int algo;
};

vector<Carro*> *fillCarro()
{
    vector<Carro*> *car = new vector<Carro*>();

    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        car->push_back(new Carro(i, (rand() % 100)+300));


    }
    return car;
}

main()
{

    vector<Carro*> *carros;
    carros = fillCarro();
    vector<Carro*>::iterator it;

    //unsigned int lastAddress;
    //Carro* lastCar;

    for (it = carros->begin(); it != carros->end(); it++)
    {
        cout << (*it)->getAlgo() << endl;

        //lastAddress = (unsigned int)*it;
    }

    cout << "\nTAM VETOR: " << carros->size() << endl << endl;

    for (it = carros->begin(); it != carros->end(); it++)
    {
        delete *it;

        //lastAddress = (unsigned int)*it;
    }

    delete carros;

    //cout << "0x" << hex << carros << endl;

    //cout << "0x" << hex << lastAddress;

    //Carro* newCar = reinterpret_cast<Carro*>(lastAddress);

    //auto vector = carros;


}
