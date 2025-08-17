#include<iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while (i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }
    
    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while (j<= ei){
        temp.push_back(arr[j++]);
    }  
    
    for (int idx = si, x=0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }  
}

void mergeSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int mid = si + ((ei - si)/2);
    mergeSort(arr, si, mid);    // left
    mergeSort(arr, mid+1, ei);  // right

    merge(arr, si, mid, ei);
}

int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for(int j = si; j < ei; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);
    return i; // i = pivotIdx
}

void quickSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei);
}

void mergeStr(string arr[], int si, int mid, int ei){
    vector<string> temp;
    int i = si;
    int j = mid+1;

    while (i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }
    
    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while (j<= ei){
        temp.push_back(arr[j++]);
    }  
    
    for (int idx = si, x=0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }  
}

void mergeSortStr(string arrstr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int mid = si + ((ei - si)/2);
    mergeSortStr(arrstr, si, mid);    // left
    mergeSortStr(arrstr, mid+1, ei);  // right

    mergeStr(arrstr, si, mid, ei);
}

void printArrStr(string arrstr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arrstr[i]<< ", ";
    }
    cout<< endl;
}

int majorityElement(vector<int> nums, int idx, int ans, int freq){
    if(idx == nums.size()){
        return ans;
    }

    if(freq == 0){
        ans = nums[idx];
    }

    if(nums[idx] == ans){
        return majorityElement(nums, idx+1, ans, freq+1);
    }else{
        return majorityElement(nums, idx+1, ans, freq-1);
    }
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}


int main(){
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    // mergeSort(arr, 0, n-1);
    // cout<< "Mergesort: ";
    // printArr(arr, n);

    // quickSort(arr, 0, n-1);
    // cout<< "Quicksort: ";
    // printArr(arr, n);

    string arrstr[] = {"sun", "earth", "mars", "mercury"};
    int m = 4;
    mergeSortStr(arrstr, 0, m-1);
    cout<<" Mergesort string: ";
    printArrStr(arrstr, m);

    vector<int> nums= {3, 2, 3, 4, 5, 3, 5, 5, 5};
    cout<< "Majority element: "<<majorityElement(nums, 0, 0, 0)<< endl;


    return 0;
}