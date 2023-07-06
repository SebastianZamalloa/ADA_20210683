#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Arista 
{
    int origen;
    int destino;
    int valor;
    Arista(){}
    Arista(int o,int d, int v):origen(o),destino(d),valor(v){}
    bool operator==(const Arista& otra) const 
    {
        return origen == otra.origen && destino == otra.destino && valor == otra.valor;
    }
    bool operator!=(const Arista& otra) const 
    {
        return !(*this == otra);
    }
};

class Grafo 
{
    public:
        int nV;
        vector<vector<Arista>> listaAdy;
        Grafo(int n):nV(n){listaAdy.resize(n);}

        void agregarArista(int origen, int destino, int valor) 
        {
            Arista arista(origen,destino, valor);
            listaAdy[origen].push_back(arista);
            Arista aristaInversa(destino, origen, valor);
            listaAdy[destino].push_back(aristaInversa);
        }

        void imprimirGrafo() 
        {
            for (int i = 0; i < nV; i++) 
            {
                cout << "Vértice " << i << " está conectado con: ";
                for (Arista arista:listaAdy[i])
                    cout<<"("<<arista.destino<<", "<<arista.valor<<")";
                cout << endl;
            }
        }

        vector<Arista> heuristica2() 
        {
            vector<Arista> solucion;
            vector<bool> visitado(nV, false);
            int nodoActual = 0; // Comenzar desde el nodo 0

            while (solucion.size() < nV - 1) 
            {
                visitado[nodoActual] = true;

                Arista aristaSeleccionada;
                int costoMinimo = numeric_limits<int>::max();

                for (Arista arista : listaAdy[nodoActual]) 
                {
                    if (!visitado[arista.destino] && arista.valor < costoMinimo) 
                    {
                        aristaSeleccionada = arista;
                        costoMinimo = arista.valor;
                    }
                }

                solucion.push_back(aristaSeleccionada);
                nodoActual = aristaSeleccionada.destino;
            }
            for (Arista arista : listaAdy[nodoActual]) 
            {
                if (arista.destino == 0) 
                {
                    solucion.push_back(arista);
                    break;
                }
            }
            return solucion;
        }
};

int main() 
{
    Grafo grafo(5);

    grafo.agregarArista(4, 0, 45);
    grafo.agregarArista(4, 3, 50);
    grafo.agregarArista(0, 3, 25);
    grafo.agregarArista(0, 2, 55);
    grafo.agregarArista(1, 3, 25);
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(1, 2, 20);
    grafo.agregarArista(2, 3, 15);  
    grafo.agregarArista(2, 4, 30);
    grafo.agregarArista(1, 4, 40);

    vector<Arista> solucion = grafo.heuristica2();

    cout <<"\nSolucion: ";
    for (Arista arista:solucion)
        cout<<"("<< arista.origen << ", "<<arista.destino <<") ";
    cout << endl;
    cout<<endl<<endl;
}
