#include<iostream>
#include<vector>
using namespace std;

void funcArr(){
    int size;
    cout<< "Enter size: ";
    cin>> size;
    int *ptr = new int[size];
    int x = 1;
    for (int i = 0; i < size; i++)
    {
       ptr[i] = x;
       cout<< ptr[i]<< " ";
       x++;
    }
    cout << endl;
    delete [] ptr; // free 
}

int* func(){ // as it returns an address , so return type is int*(i.e. pointer)
    int *ptr = new int; // an adress allocated for ptr in heap memory
    *ptr = 1200; // *ptr means * is used as dereference opearator , Derefered ptr and overwrite its value with 1200
    cout << "ptr points to "<< *ptr << endl;
    return ptr;
}

vector<int> pairSum(vector<int> vec, int target){ // Time complexity = O(n^2)
    int st = 0, end = vec.size() - 1, currSum = 0;
    vector<int> ans;
    while(st < end){
        currSum = vec[st] + vec[end];
        if (currSum == target)
        {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        } else if (currSum > target)
        {
           end--;
        } else
        {
            st++;
        }
    }
    return ans; 
}


int main(){
    // Dynamic memory allocation
    //funcArr();

    // int *x = func(); // created apointer to store the returned address
    // cout << *x<< endl; // derefered the address in pointer and printed its value

    // VECTORS
/*   // Basics
    vector<int> vec1 = {1, 2, 3, 4};
    cout<< vec1.size()<< "\n";
    vector<int> vec2(10, -1);
    cout<< vec2.size()<< "\n";
    for(int i = 0; i < vec2.size(); i++){
        cout<< vec2[i] << " ";
    }
    cout<< endl;
*/

/*   // Vector Implemention in memory
    vector<int> vec = {1, 2, 3, 4};
    cout<< "size = "<< vec.size()<< endl;
    cout<< "capacity = "<< vec.capacity()<< endl;

    vec.push_back(5);
    cout<< "size = "<< vec.size()<< endl;
    cout<< "capacity = "<< vec.capacity()<< endl;

    vec.pop_back();
    cout<< "size = "<< vec.size()<< endl;
    cout<< "capacity = "<< vec.capacity()<< endl;
*/

    //pair sum
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = pairSum(vec, target);
    cout<< ans[0]<< ","<< ans[1]<< endl;



    return 0;
}