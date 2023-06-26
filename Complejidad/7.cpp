#include <iostream>
using namespace std;

int main()
{
    int count = 0;


    int n = 1000;count++;
    count++;if(n%2 == 0)
    {
        cout<<"par"<<endl;
        count++;
    }
    else
    {
        cout<<"impar"<<endl;
        count++;
    }
    //3*n^0 = 3*1     O(1)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //Verificado
}
