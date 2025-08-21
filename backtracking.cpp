#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i< n; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

void changeArr(int arr[], int n, int i){
    if(i == n){
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2; // backtracking
}

void subsets(string str, string subset){
    if (str.size() == 0){
        cout<< subset<< endl;
        return;
    }

    char ch = str[0];
    subsets(str.substr(1, str.size()-1), subset+ch); // yes choice
    subsets(str.substr(1, str.size()-1), subset); // No choice
}

void permutations(string str, string permStr){
    int n = str.size();
    if(n == 0){
        cout<< permStr<< endl;
        return;
    }

    for(int i = 0; i< str.size(); i++){
        char ch = str[i];
        //permStr = permStr + str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);
        permutations(nextStr, permStr + ch);
    }
}

int main(){
    int arr[5];
    int n = 5;
    // changeArr(arr, n, 0);
    // printArr(arr, n);

    string str = "abc";
    subsets(str, "");

    string str = "abc";
    string ans = "";
    permutations(str, ans);
    return 0;
}