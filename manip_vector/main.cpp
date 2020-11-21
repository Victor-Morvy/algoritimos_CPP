#include <iostream>
#include <vector>

using namespace std;

vector<string> *criaVetor(string name, string path)
{
    vector<string> * p = new vector<string>;
    p->push_back(name);
    p->push_back(path);

    return p;

}

void addVector(string name, string path, vector<vector<string>> &vetor)
{
    vector<string> *tmp = criaVetor(name, path);
    vetor.push_back(*tmp);
}

void removeVector(int index, vector<vector<string>> &vetor)
{
    delete &vetor[index];
    vetor.erase(vetor.begin() + index);
}

int main()
{
    vector<vector<string>> vetorOriginal;

    //Alimentando vetor, alocando memória no heap
    addVector("Oi", "Tudo bem?", vetorOriginal);
    addVector("Sim", "Mao", vetorOriginal);
    addVector("Nao", "Vaca", vetorOriginal);
    addVector("Talvez", "bem tambem", vetorOriginal);

    //printando valores atualmente
    for(vector<string> v: vetorOriginal)
    {
        cout << "Val1: " << v[0] << " | Val2: " << v[1] << endl;
    }

    cout << "\nREMOVENDO INDICE 1 E PRINTANDO NOVAMENTE\n" << endl;
    //deletando do heap objeto alocado e removendo do vetor
    removeVector(1, vetorOriginal);

    //printando valores de novo
    for(vector<string> v: vetorOriginal)
    {
        cout << "Val1: " << v[0] << " | Val2: " << v[1] << endl;
    }

    return 0;
}
