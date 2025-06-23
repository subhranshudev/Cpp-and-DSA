#include<iostream>
#include<algorithm>
using namespace std;

void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<",";
    }
    cout<<endl;
}

void printCharArr(char *arr, int n){
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

void insertionSort(int *arr, int n){
    // Time complexity = O(n^2)
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1;
        while (prev >= 0 && arr[prev] > curr)
        {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        //arr[prev+1] = curr; // No need, Because when we swap the values arrange accordingly
        
    }
    printArr(arr, n);
    
}

void countingSort(int arr[], int n){
    int freq[100000];
    int maxVal = INT32_MIN, minVal = INT32_MAX;
    // Creating the frequency array calculating the min and max value of given array
    // Time complexity = O(n)
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(arr[i], minVal);
        maxVal = max(arr[i], maxVal);
    }

    // updating the original array
    // Time complexity = O(n + range)
    for (int i = minVal, j = 0; i <= maxVal; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
        
    }
    printArr(arr, n);
 
}

void sortCharacters(char arr[], int n){
    for (int i = 1; i < n; i++)
    {
       char curr = arr[i];
       int prev = i-1;
       while (prev>=0 && arr[prev] > curr)
       {
            swap(arr[prev], arr[prev + 1]);
            prev--;
       }
    }
    printCharArr(arr, n);
    
}

int main(){
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    // bubbleSort(arr, n);
    // selsectionSort(arr, n);
    // insertionSort(arr, n);

    int arr2[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    // countingSort(arr2, 8);

/*   //Inbuilt Sort
    //sort(arr2, arr2+8);  // Ascending Order
    sort(arr2, arr2+8, greater<int>());  // Descending Order
    printArr(arr2, 8);
*/

    // Practice Question
    char ch[6] = {'f', 'd', 'a', 'c', 'e', 'b'};
    sortCharacters(ch, 6);


    return 0;
}