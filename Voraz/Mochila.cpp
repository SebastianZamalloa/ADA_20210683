#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Objeto {
    T valor;
    T peso;
};

float mochila(int capacidadMochila, vector<Objeto<float>> elementos) 
{
    int peso = 0;
    float rpta = 0;
    while(peso < capacidadMochila)
    {
        float max = 0;
        int j = 0;
        for(int i = 0; i<elementos.size(); i++)
        {
            if(elementos[i].valor/elementos[i].peso >= max)
            {j=i;max =elementos[i].valor/elementos[i].peso;}
        }
        if(capacidadMochila >= peso + elementos[j].peso)
        {
            peso += elementos[j].peso;
            rpta += elementos[j].valor;
        }
        else
        {
            rpta += elementos[j].valor*((capacidadMochila-peso)/elementos[j].peso);
            peso = capacidadMochila;
        }
        elementos.erase(elementos.begin()+j);
    }
    return rpta;
}

int main() {

    vector<Objeto<float>> elementos = {
        {25, 18}, 
        {24, 15},
        {15, 10}  
    };

    int capacidadMochila = 20;

    cout << "El valor máximo que se puede obtener en la mochila es: " << mochila(capacidadMochila, elementos) << endl;

    return 0;
}
