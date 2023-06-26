#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count = 0;

    int n;
    cout<<"Ingrese n: ",cin>>n;

    for(int i = 0; i<=n ; i++, count++) //n+2   
    {
        int j = 1;count++; //n+1
        while(j < n)// ((log 2 n^2 - 1)*(n+1)
        { 
            count++;
            cout<<j<<endl;count++; //(log 2 n^2 - 2)*(n+1)
            j *= 2;count++; //(log 2 n^2 - 2)*(n+1)
        }count++;
    }count++;
    // 6n*log2 n + 6log2 n - 3n - 2 = (6n + 6)(log2 n) - 3n - 2         O(n*log2 n)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //Semi Verificado, los resultados de internet dicen que es n*log n sin más, pero debe ser base 2
}
