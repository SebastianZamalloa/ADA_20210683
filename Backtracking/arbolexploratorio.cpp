#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item 
{
    int peso;
    int val;
};

int mochilaExploratorio(vector<item> lista, int cap, int i) 
{
    if (i >= lista.size() || cap == 0) return 0;
    if (lista[i].peso > cap)
        return mochilaExploratorio(lista, cap, i + 1);
    else
    {
        int include = lista[i].val + mochilaExploratorio(lista, cap - lista[i].peso, i + 1);
        int exclude = mochilaExploratorio(lista, cap, i + 1);
        return max(include, exclude);
    }
}

int main() 
{
    vector<item> lista = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int q = 7;
    cout << "Valor maximo: " << mochilaExploratorio(lista,q,0) << endl;
}
