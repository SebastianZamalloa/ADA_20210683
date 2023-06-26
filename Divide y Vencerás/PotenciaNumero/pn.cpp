#include <iostream>

using namespace std;

int calcularPotencia(int base, int exp) 
{
    if (exp == 0)
        return 1;
    int m = calcularPotencia(base, exp/2);
    int resultado = m * m;
    if (exp%2 == 1)
        resultado *= base;
    return resultado;
}

int main() 
{
    int base;
    int exp;
    cout << "Ingrese la base: ",cin>>base;
    cout << "Ingrese el exponente: ",cin>>exp;
    cout << "Resultado: "<<calcularPotencia(base,exp)<<endl;
    return 0;
}
