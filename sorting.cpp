#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<",";
    }
    cout<<endl;
}

void bubbleSort(int *arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
            
        }

        if (!isSwap)
        {
            // Array is already sorted
            return;
        }
        
    }

    printArr(arr, n);
}

void selsectionSort(int *arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }  
        }
        swap(arr[i], arr[minIndex]);
        
    }
    printArr(arr, n);
    
}





int main(){
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
   // bubbleSort(arr, n);
    selsectionSort(arr, n);
    


    return 0;
}