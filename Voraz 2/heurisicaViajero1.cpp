#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Arista 
{
    int destino;
    int valor;

    Arista(int d, int v):destino(d),valor(v){}
};

class Grafo 
{
    public:
        int nV;
        vector<vector<Arista>> listaAdy;
        Grafo(int n):nV(n){listaAdy.resize(n);}

        void agregarArista(int origen, int destino, int valor) {
            Arista arista(destino, valor);
            listaAdy[origen].push_back(arista);

            Arista aristaInversa(origen, valor);
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

        vector<int> heuristica1(int s) 
        {
            vector<int> solucion;
            solucion.push_back(s); 
            int cost = 0;
            while (solucion.size() < nV) 
            {
                int ultimoNodo = solucion.back();
                int nodoSeleccionado = -1;
                int distanciaMinima = numeric_limits<int>::max();
                for (Arista arista : listaAdy[ultimoNodo]) 
                {
                    if (find(solucion.begin(), solucion.end(), arista.destino) == solucion.end()) 
                    {
                        if (arista.valor < distanciaMinima) 
                        {
                            distanciaMinima = arista.valor;
                            nodoSeleccionado = arista.destino;
                        }
                    }
                }
                solucion.push_back(nodoSeleccionado);
            }
            cout<<"\nCoste total: "<<cost<<endl;
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

    vector<int> solucion = grafo.heuristica1(4);

    cout <<"Orden de visita: ";
    for(int nodo:solucion) 
        cout<<nodo<<" ";
    cout<<endl<<endl;
}
