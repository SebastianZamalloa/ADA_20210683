#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &,int, int , int );
void merge_sort(vector<int> &arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
void merge(vector<int> &arr, int low, int high, int mid)
{
    int i, j, k, c[100];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        arr[i] = c[i];
}

void displayArray(vector<int> arr) 
{ 
    for(auto i:arr)
        cout<<i<<"\t";      
} 

int main()
{
    vector<int> arr;
    int a = -1;
    while(a != 0)
    {
        cout<<"Ingrese siguiente dato de la lista: ",cin>>a;
        if(a == 0)
            break;
        arr.push_back(a);
    }
    cout<<"Arreglo original: "<<endl;
    displayArray(arr);
    merge_sort(arr, 0, arr.size()-1);
    cout<<"\nArreglo ordenado: \n";
    displayArray(arr);
}
