#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (vector<int> &arr, int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
void quickSort(vector<int> &arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pivot = partition(arr, low, high); 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void displayArray(vector<int> arr, int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"\t"; 
      
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
    displayArray(arr,arr.size());
    cout<<endl;
    quickSort(arr, 0, arr.size()-1); 
    cout<<"Arreglo ordenado: "<<endl; 
    displayArray(arr,arr.size()); 
}
