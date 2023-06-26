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
        count++;if(i%2 == 0) //n+1
        {
            count++;
            cout<<i<<endl;  //(n+1)/2
        }
    }count++;
    //2n+3 + n+1/2 = (5n+7)/2   O(n)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //verificado
}
