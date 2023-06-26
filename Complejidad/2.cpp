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
        for(int j = i; j<=n; j++, count++) //(n+1)(n+2)/2 + (n+1)  =  (n^2+5n+4)/2    
        {
            cout<<i<<", "<<j<<endl; count++; // (n+1)(n+2)/2 =  (n^2+3n+2)/2    
        }count++;
    }count++;
    // n+2 + (2n^2+8n+6)/2 = n+2 + n^2+4n+3 = n^2+5n+5         O(n^2)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //Verificado
}
