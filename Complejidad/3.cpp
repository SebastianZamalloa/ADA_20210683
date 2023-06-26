#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count = 0;
    string A;
    string B;

    cout<<"Ingrese A: ",cin>>A;
    cout<<"Ingrese B: ",cin>>B;

    for(int i = 0; i<A.size(); i++, count++) //A+1   
    {
        for(int j = 0; j<B.size(); j++, count++) //A*(B+1) = A*B + A
        {
            cout<<A[i]<<", "<<B[j]<<endl; count++; //(A*B)
        }count++;
    }count++;
    // 2*A*B + 2A + 1    O(A*B)
    cout<<"\nConteo: "<<count<<endl<<endl;
    //Verificado
}
