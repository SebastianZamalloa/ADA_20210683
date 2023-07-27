#include <iostream>
#include <vector>
using namespace std;
int superInt = 100000000;

int minCoins(vector<int> coins, int amount) 
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, superInt));
    for (int i = 0; i<=n; i++)
        dp[i][0] = 0;
    for (int i = 1; i<=n; i++) 
    {
        for (int j = 1; j<=amount; ++j) 
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amount] == superInt ? -1 : dp[n][amount];
}

int main() 
{
    int amount, n;
    cout<<"Ingrese la cantidad: ",cin>>amount;
    cout<<"Ingrese el número de monedas: ",cin>>n;
    vector<int> coins(n);
    cout<<"Ingrese los valores de las monedas: ";
    for (int i = 0; i < n; ++i)
        cin>>coins[i];
    cout<<"Cantidad mínima de monedas necesarias: "<<minCoins(coins, amount)<<endl;
}
