#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& nums, int target) 
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) 
    {
        // 0 3    0 2     
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

void displayArray(vector<int> arr) 
{ 
    for(auto i:arr)
        cout<<i<<"\t";      
} 

int main() 
{
    vector<int> nums;
    int a = -1;
    while(a != 0)
    {
        cout<<"Ingrese siguiente dato de la lista: ",cin>>a;
        if(a == 0)
            break;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end(),less<int>());

    cout<<"\nArreglo original: "<<endl;
    displayArray(nums);

    cout<<"Inserta el numero que quieres buscar: ",cin>>a;
    int result = binarySearch(nums, a);
    if(result != -1)
        cout << "El elemento "<<a<<" fue encontrado en el indice: "<<result<<endl;
    else
        cout << "El elemento "<<a<<" no fue encontrado\n";
}
