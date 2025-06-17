#include<iostream>
using namespace std;

int linearSearch(int *arr, int n, int key){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        } 
    }
    return -1;
    
}

int printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<< ",";
    }
    

}

void swapNum(int &firstVal, int &lastVal){
        int temp = firstVal;
        firstVal = lastVal;
        lastVal = temp;
}


int main() {
/*
    int arr[5];
    int n = sizeof(arr) / sizeof(int);

    //input
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    // output
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << ",";
    }
*/

/*   // Taking size of array from user:
    int n;
    cout<< "Enter the size of array: ";
    cin >>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin>> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << ",";
    }
*/

/*
    // Find largest and smallest in array:
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int); 
    int max = arr[0] ;
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        } 
        if (arr[i]< min)
        {
            min = arr[i];
        }
        
    }
    cout<< "Largest value = "<< max << endl;
    cout<< "Smallest value = "<< min;
*/

/*
    //Linear Search
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);
    cout<< linearSearch(arr, n, 20) ;
*/ 

    // Reverse an array
/* // with extra space
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int);
    int copyArr[n];

    for (int i = 0; i < n; i++)
    {
        int j = n-i-1;
        copyArr[i] = arr[j];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = copyArr[i];
    }
    printArr(arr, n);
*/


    // without extra space
      int arr[] = {5, 4, 3, 9, 2};
      int n = sizeof(arr) / sizeof(int);
      int start = 0;
      int end = n-1;

      while (start < end)
      {
        swapNum(arr[start], arr[end]); // we can also use the built-in swap() method 
        start++;
        end--;
      }
      printArr(arr, n);




    return 0;
}