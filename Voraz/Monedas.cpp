#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> cambioMonedas(float cantidad, vector<float>& denominaciones) 
{
    vector<float> resultado;
    sort(denominaciones.rbegin(), denominaciones.rend());
    for (auto i:denominaciones) 
    {
        cout<<i<<endl;
        while (cantidad >= i) {
            resultado.push_back(i);
            cantidad -= i;
        }
    }
    if(cantidad != 0)
        cout<<"\nNo completado\n";
    return resultado;
}

int main() 
{
    float q; float k = 1;
    vector<float> money;
    cout<<"\nQue cantidad dinero debemos de devolver: ",cin>>q;
    cout<<"\nQue monedas disponemos: ";
    while(k != 0)
    {
        cout<<"\nIngrese: ",cin>>k;
        if(k == 0)
            break;
        money.push_back(k);
    }
    vector<float> result = cambioMonedas(q,money);
    cout<<"El cambio de "<<q<<" se puede dar con las siguientes monedas:"<<endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout<<endl;
}
