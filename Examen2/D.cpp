#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> l, vector<int> r)
{
	return l[0] < r[0];
}

int main()
{
    int t, m;
    cin>>t;
    while(t--)
    {
        vector<vector<int>> list;
        cin>>m;
        int l,r,L=0;
        while(cin>>l>>r)
        {
            if(l==0&&r==0)
                break;
            list.push_back({l,r});
        }
        sort(list.begin(),list.end(),compare);
        vector<vector<int>> newl;
        while(L < m)
        {
            int j = 0;
            for(auto i: list)
            {
                j++;
                if(i[0]<= L && i[1] > L)
                {
                    newl.push_back(i);
                    L = i[1];   
                    break;
                }
            }
            if(j == list.size())
                break;
        }
        if(L<m)
            cout<<0<<endl;
        else
        {
            cout<<newl.size()<<endl;    
            for(auto i:newl)
                cout<<i[0]<<" "<<i[1]<<endl;
        }
        if(t)
            cout<<endl;
    }
}
