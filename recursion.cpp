#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    if (n == 0) {
        return 1;
    }

    return n*factorial(n-1);
}

void printNums(int n){
    if (n == 0){    //Base case
        return;
    }
    
    cout<< n<<" ";
    printNums(n-1);
}

void func(){
    cout<< "function calles....kaam"<< endl;
    func();
}

int sumN(int n){
    if (n == 1){
        return 1;
    }
    
    return n + sumN(n-1);
}

int fibo(int n){
    if (n == 0 || n == 1){
        return n;
    }

    return fibo(n-1)+fibo(n-2);
}

bool isSorted(int arr[], int n, int i){
    if (i == n-1){
        return true;
    }

    if (arr[i] > arr[i+1]){
        return false;
    }

    return isSorted(arr, n, i+1); 
}

int firstOccurance(vector<int> arr, int i, int target){
    if(i == arr.size()){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }
    return firstOccurance(arr, i+1, target);
}

// x to the power n
int pow(int x, int n){  // Time Complexity = O(n)
    if (n == 0){
        return 1;
    }

    return x*pow(x, n-1);   
}

int pow2(int x, int n){    // Time Complexity = O(log n)
    if (n == 0){
        return 1;
    }
    
    int halfPower = pow2(x, n/2);
    int halfPowerSquare = halfPower*halfPower;
    if (n % 2 != 0)
    {
        return x*halfPowerSquare;
    }
    return halfPowerSquare;
    
}

int tilingProblem(int n){
    // Base case
    if (n == 0 || n == 1){
        return 1;
    }
    
    // //vertical 
    // int ans1 = tilingProblem(n-1);
    // //Horizontal
    // int ans2 = tilingProblem(n-2);
    // return ans1 + ans2;

    return tilingProblem(n-1) + tilingProblem(n-2);
}

void removeDuplicates(string str, string ansStr, int i, bool map[]){
    if (i == str.size()){
        cout<< ansStr<< endl;
        return;
    }
    
    int index = str[i] - 'a';
    if (map[index]){
        removeDuplicates(str, ansStr, i+1, map);
    } else{
        ansStr = ansStr + str[i];
        map[index] = true;
        removeDuplicates(str, ansStr, i+1, map);  
    }   
}

int friendsPairing(int n){
    if (n == 1 || n == 2)
    {
        return n;
    }
    
    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}

void binaryStrings(int n, int lastPlace, string ans){
    if(n == 0){
        cout<< ans<< endl;
        return;
    }
    if (lastPlace != 1){
        binaryStrings(n-1, 0, ans+'0');
        binaryStrings(n-1, 1, ans+'1');
    }else{
        binaryStrings(n-1, 0, ans+'0');
    }
    
}

void binaryStrings(int n, string ans){
    if(n == 0){
        cout<< ans<< endl;
        return;
    }
    if (ans[ans.size()-1] != '1'){    // !=1 is important, Never use ==0
        binaryStrings(n-1, ans+'0');
        binaryStrings(n-1, ans+'1');
    }else{
        binaryStrings(n-1, ans+'0');
    }
    
}

int binarySearch(int arr[], int st, int end, int key){
    if(end < st){
        return -1;
    }
    int mid = st +((end-st)/2);
    if(arr[mid] == key){
        return mid;
    }else if (arr[mid] < key){
        return binarySearch(arr, mid+1, end, key);
    } else{
        return binarySearch(arr, st, mid-1, key);
    }
}

void allOccurences(int arr[], int size, int key, int i){
    if (i == size){
        return;
    }
    
    if (arr[i] == key){
        cout<< i<< " ";
    } 

    allOccurences(arr, size, key, i+1);  
}

int countSubstring(string str, int start, int i, int count){
    if (start == str.length()){
        return count;
    }
    if(i == str.length()){
        return countSubstring(str, start+1, start+1, count);
    }

    if (str[start] == str[i]){
        count++; 
    }

    return countSubstring(str, start, i+1, count);
}

void towerOfHanoi(int n, string src, string helper, string dest){
    if(n > 0){
        towerOfHanoi(n-1, src, dest, helper);
        cout<< "Moving disc from "<< src << " to "<< dest<< endl;
        towerOfHanoi(n-1, helper, src, dest);
    }
}

// Count good numbers --> Leetcode-1922
long long fastExpo(long long x, long long n, long long mod){
        long long ans = 1;
        while(n > 0){
            int lastBit = n&1;
            if(lastBit){
                ans = (ans*x)%mod;
            }
            
            x= (x*x)%mod;
            n = n>>1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod = 1000000007;
        long long evenPos = (n+1)/2;
        long long oddPos = n/2;

        return (int)(fastExpo(5, evenPos, mod) * fastExpo(4, oddPos, mod) % mod);
    }


int main(){
    // int ans = factorial(5);
    // cout<< ans<< endl;

    //printNums(5);

    // Stack Overflow
    //func();

    // int sum = sumN(5);
    // cout<< "sum = "<< sum<< endl;

    // int n = 5;
    // int fibonacci = fibo(n);
    // cout<< n << "th Fibonacci is = "<< fibonacci<< endl;

/*    // Check the array is sorted or not
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 4, 3, 5};
    cout<< isSorted(arr2, 5, 0)<< endl;
*/

/*    // Search the 1st occurence
    vector<int> arr = {1, 2, 3, 3, 3, 4};
    int i = firstOccurance(arr, 0, 2);
    cout<< "First Occurence = "<< i;
*/

/*    // x to the power n 
    cout<< pow2(2, 3)<< endl;
    cout<< pow2(2, 2)<< endl;
*/

/*    // Tiling Problem
    int n = 4;
    int ways = tilingProblem(n);
    cout<< "No. of ways = "<< ways<< endl;
*/

/*    // Remove Duplicates
    string str = "appnnacollege";
    string ansStr = "";
    bool map[26] = {false};
    removeDuplicates(str, ansStr, 0, map);
*/

    // // Friends Pairing
    // cout<< friendsPairing(4) << endl;

/*    // Binary Strings without no consecutive 1
    string ans = "";
    int n = 3;
    //binaryStrings(n, 0, ans);
    binaryStrings(n, ans);
*/

/*    vector<int> arr= {1, 2, 3, 4, 5};
    arr.resize(2);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<< endl;
    }
*/

    //  ASSIGNMENT
/*    // Q.1 --> Binary Search
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int key = 2;
    int n = 7;
    cout<< binarySearch(arr, 0, n-1, key)<< endl;
*/
    
/*    // Q.2
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 2;
    allOccurences(arr, 9, key, 0);
*/

/*    // Q.3
    string str = "abcab";
    string str2 = "aba";
    cout<< "count: " << countSubstring(str2, 0, 0, 0)<< endl;
*/

/*   // Tower of Hanoi
    //towerOfHanoi(3, "source", "helper", "destination");
    towerOfHanoi(3, "A", "B", "C");
*/

// int a = -1;
// int b = 2;
// int n = a/b;
// //cout << "n = "<< n<< endl;

// double x = (1/2)%2;
// cout<<" x = "<< x<< endl;

   
    cout <<  countGoodNumbers(50)<< endl;
    
    

    return 0;
}