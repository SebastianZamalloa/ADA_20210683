#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void medianCalculate(vector<int>list)
{
    sort(list.begin(),list.end());
    int n = list.size();
    if(n%2!=0)
        cout<<list[n/2]<<endl;
    else
        cout<<(list[n/2]+list[n/2-1])/2<<endl;
}

int main()
{
    vector<int> input;
    int x;
    while(cin>>x)
    {
        input.push_back(x);
        medianCalculate(input);
    }
    return 0;
}
