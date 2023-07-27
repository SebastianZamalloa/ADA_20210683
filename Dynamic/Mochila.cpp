#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mochila(int len,vector<int>weights,vector<int>val) 
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(len + 1, 0));
    for (int i = 1; i<=n; i++) 
    {
        for (int w = 1; w<=len; w++) 
        {
            if (weights[i-1]<=w) 
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-weights[i-1]]); 
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][len];
}

int main() 
{
    int len, n;
    cout<<"Ingrese la capacidad: ",cin>>len;
    cout<<"Ingrese el numero de elementos: ", cin>>n;
    vector<int> weights(n);
    vector<int> val(n);
    cout<<"Ingrese los pesos de los elementos: ";
    for (int i = 0; i<n; i++)
        cin>>weights[i];
    cout<<"Ingrese los valores de los elementos: ";
    for (int i = 0; i<n; ++i)
        cin >> val[i];
    cout<<"El valor máximo que se puede obtener es: "<<mochila(len, weights, val)<<endl;
}
