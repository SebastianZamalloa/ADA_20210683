#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int n;
    cout<<"Ingrese n: ",cin>>n;


    int i = 1; count++; // 1
    while(i < n) // log2 n^2 - 1
    {
        count++;
        count++;cout<<i<<endl; //log2 n^2 - 2
        count++;i *= 2; //log2 n^2 - 2
    }count++;
    // 6*log2 n - 4         O(log2 n)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //Verificado
}
