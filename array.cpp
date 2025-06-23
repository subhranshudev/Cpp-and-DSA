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

int binarySearch(int *arr, int n, int key) {
    int start = 0, end = n-1;
    
    while (start <= end)
    {
        int mid = (start+end)/2;

        if (arr[mid] == key)
        {
           return mid;
        } else if (arr[mid] < key)
        {
            start = mid + 1;
        } else {
            end = mid - 1;
        }  
    }
   return -1;
   cout<< "done";
}

void printSubarray(int *arr, int n){
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // cout<< "("<< start<< ","<< end<< ")"<< " ";

            for (int i = start; i <=end; i++)
            {
                cout<< arr[i];
            }    
            cout<< ",";

        }
        cout<< "\n";
        
    }
}

void subArraySum1(int *arr, int n){
    int maxSum = INT32_MIN;
    for (int start = 0; start <n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum = currSum + arr[i];
            }
            //cout<< currSum<< ",";
            maxSum = max(currSum, maxSum);
        }
        // cout<<endl;
    }
    cout<< "Maximum subarray sum = "<< maxSum<< endl;
}

void subArraySum2(int *arr, int n){
    int maxSum = INT32_MIN;
    for (int start = 0; start <n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum = currSum + arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout<< "Maximum subarray sum = "<< maxSum<< endl;
}

//Kadane's Algorithm
void subArraySum3(int *arr, int n){
    int currSum = 0;
    int maxSum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum = currSum + arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
        
    }
    
    cout<< "The maximum Subarray sum = "<< maxSum<< endl;
    
}

// Buy and Sell stock
int maxProfit(int *prices, int n){
    int bestBuy[100000]; // we cant do dynamic array creation in a function like bestBuy[n]
    bestBuy[0] = INT32_MAX;
    cout<< bestBuy[0]<<",";
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        cout<<bestBuy[i]<<",";
    }
    cout<< endl;
 
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int profit = prices[i] - bestBuy[i];
        // if (profit > maxProfit) {
        //     maxProfit = profit;
        // }  or
        maxProfit = max(profit, maxProfit);
    }
    // Time complexity --> O(n + n) = O(2n) = O(n)
    cout<< "Maximum Profit = "<< maxProfit<< endl;
    
}

//Trap rain water
int trapWater(int *heights, int n){
    int leftMax[20000];
    int rightMax[20000];
    leftMax[0] = heights[0];
    rightMax[n-1] = heights[n-1];
    
   // cout<< leftMax[0]<< ",";
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
       // cout<< leftMax[i]<< ",";
    }
    //cout<< endl;
    
    //cout<< rightMax[n-1] << ",";
    for (int i = n-2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
       // cout<< rightMax[i]<< ",";
    }
    //cout<< endl;

    int totalWaterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int minOfHeight = min(leftMax[i], rightMax[i]);
        int heightOfWater = minOfHeight - heights[i];
       // cout<< heightOfWater<<",";
        if (heightOfWater >= 0)
        {
            totalWaterTrapped = totalWaterTrapped + heightOfWater;
        }
        
    }
    cout<< endl;
    cout<< "Total water trapped = "<< totalWaterTrapped;
    return totalWaterTrapped;

}

// ASSIGNMENT
bool isRepeating1(int *nums, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }  
        }
        return false;

    }
    
} // Time complexity = O(N^2)

// A slight more optimal approch --> Using sorting

int searchTarget1(int *nums, int n, int target){ // Linear Search
    for (int i = 0; i < n; i++)
    {
        if (target == nums[i])
        {
            return i;
        } 
    }
    return -1;
    
} //Time complexity = O(n), Will solve again after learning time and space complexity properly

int searchTarget2(int nums[], int n, int target){
    int start = 0;
    int end = n-1;

    while (start <= end)
    {
        int mid = (start+end)/2;
        if (target == nums[mid])
        {
            return mid;
        } else if (nums[start] <= nums[mid-1])
        {
            if (target>= nums[start] && target <= nums[mid-1])
            {
                end = mid-1;
            }else{
                start = mid+1;
            }
            
        } else {
            if (target >=nums[mid+1] && target<= nums[end])
            {
                start = mid+1;
            } else{
                end = mid-1;
            }
            
        }
        
        
    }
    return -1;
}

int maxProduct(int *nums, int n){
    int currProduct = 1;
    int maxProd = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        currProduct = currProduct*nums[i];
        maxProd = max(currProduct, maxProd);
        if (currProduct < 0)
        {
            currProduct = 1;
        }
    }
    return maxProd;
  
}

int main() {
    // PART-1-->
/*  int arr[5];
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

/*  // Find largest and smallest in array:
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

/*  //Linear Search
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

/*  // without extra space
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
*/

/*    // Binary Search
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr)/ sizeof(int);
    cout<< binarySearch(arr, n, 13);
*/

/*   // Pointer Arithematic
     int a = 10;
    int *aptr = &a;
    cout<< aptr<< endl;
    aptr++;
    cout<< aptr<< endl;
    aptr--;
    cout<< aptr<< endl;  

    int b = 20;
    int *bptr = &b;
    cout<< bptr<< endl;
    bptr = bptr + 3;
    cout<< bptr<< endl;
    bptr = bptr - 3;
    cout<< bptr<< endl;  

    int c = 30;
    int *ptr1 = &c;
    int *ptr2 = ptr1 + 3;
    cout<< ptr1<< endl;
    cout<< ptr2<< endl;
    cout<< (ptr2 - ptr1)<< endl;

    cout<< (ptr2 > ptr1)<< endl;
    cout<< (ptr2 < ptr1)<< endl;
    cout<< (ptr1 == &c)<< endl;
*/

/*  // Print Subarrays
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    printSubarray(arr, n);
*/

/*  // Max subarray sum
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    subArraySum1(arr, n);
    subArraySum2(arr, n);
    // Kadane's algorithm --> It is an algorithm which calculate the maximum subarray sum without calculating all the subarray sum
    subArraySum3(arr, n);
*/

/*   // Buy and Sell Stocks
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices)/ sizeof(int);
    maxProfit(prices, n);
*/

/*   // Trapping Rain Water
    int heights[7] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(int);
    trapWater(heights, n);
*/
   
// ASSIGNMENT
/*   // 1. After learning sorting will solve it with more optimal approach
    int nums1[] = {1, 2, 3, 4};
    int n1 = sizeof(nums1) / sizeof(int);
    int nums2[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int n2 = sizeof(nums2) / sizeof(int);
    bool repeating = isRepeating1(nums2, n2);
    if (repeating)
    {
       cout<< "Repeating";
    } else
    {
        cout<< "Not repeating";
    }
*/    
  
/*  //2. It is asked to solve it with Time complexity O(log n), After learning time and space complexity I will solve it again
    //    Now solving with my approach --> Linear Search -->Time complexity = O(n)
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(int);
    int target = 3;
    int index = searchTarget1(nums, n, target);
    cout<<"Index = "<< index;
*/

    // Binary Search approach-->
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(int);
    int target = 6;
    int index = searchTarget2(nums, n, target);
    cout<< "index = "<< index;
    

   
/* // 3.  
    int nums[] = {-2, 0 , -1};

    int n = sizeof(nums) / sizeof(int);
    int maxProd = maxProduct(nums, n);
    cout<< "Maximum Product = "<< maxProd;
*/
    // After learning vector will solve all the assignments agin in coding platforms

    return 0;
}