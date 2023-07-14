#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 0;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>X(0,n);
        for(int j = 0;j<n;j++)
            cin>>X[j];
        int max = X[0];
        int q = 1;
        for(int i = 1;i<n-1;i++)
        {
            if(max + X[i] < X[i+1])
            {
                max += X[i];
                q++;
            }
        }
        q++;
        cout<<q<<endl;
    }
}
