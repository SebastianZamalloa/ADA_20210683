#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int infinito = 0x3f3f3f3f;
vector<vector<int>> list;

bool compare(vector<int>a,vector<int>b)
{
    return a[0] < b[0];
}

float distancia(vector<int>a,vector<int>b)
{
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

float distanciaMinima(int l,int r)
{
    if(l==r)
        return infinito;
    if(l+1==r)
        return distancia(list[l],list[r]);
    int mitad = (l+r)>>1;
    float d = min(distanciaMinima(l,mitad),distanciaMinima(mitad+1,r));

    for(int i = mitad; i >= l && list[mitad][0]-list[i][0]<d; i--)
        for(int j = mitad+1; j <= r && list[j][0]-list[mitad][0]<d; j++)
            d = min(d,distancia(list[i],list[j]));
    return d;  
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        list.clear();
        int x,y;
        for(int i = 0; i<n; i++)
        {
            cin>>x>>y;
            list.push_back({x,y});
        }
        sort(list.begin(),list.end(),compare);
        float min = distanciaMinima(0,n-1);
        if(min<10000)
            cout<<min<<endl;
        else
            cout<<"INFINITY"<<endl;
    }
}
