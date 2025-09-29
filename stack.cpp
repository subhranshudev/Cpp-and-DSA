#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
using namespace std;

// create Stack using vector
class Stack{
    vector<int> vec;
public:
    void push(int val){ // TC = O(1)
        vec.push_back(val);
    }

    void pop(){ // TC = O(1)
        if(isEmpty()){
            cout<< "Stack is empty. \n";
            return;
        }
        vec.pop_back();
    }

    int top(){  // TC = O(1)
        if(isEmpty()){
            cout<< "Stack is empty. \n";
            return -1;
        }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

// Using template class
template<class T>
class tempStack{
    vector<T> vec;
public:
    void push(T val){ // TC = O(1)
        vec.push_back(val);
    }

    void pop(){ // TC = O(1)
        if(isEmpty()){
            cout<< "Stack is empty. \n";
            return;
        }
        vec.pop_back();
    }

    T top(){  // TC = O(1)
        // if(isEmpty()){
        //     cout<< "Stack is empty. \n";
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

template<class T>
class tempStackll{
    list<T> ll;
public:
    void push(T val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    T top(){
        return ll.front();
    }

    bool isEmpty(){
        return ll.size() == 0;
    }
};

void pushAtBottom(stack<int> &s, int val){  //TC = O(n)
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

string reverseString(string str){
   string ans;
   stack<char> s;

   for(int i = 0; i< str.size(); i++){
    s.push(str[i]);
   } 

   while(!s.empty()){
    ans += s.top();
    s.pop();
   }

   return ans;
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<< s.top()<< ' ';
        s.pop();
    }
    cout<< '\n';
}

void stockSpanProblem(vector<int> stock, vector<int> &span){    // TC = O(n)
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for(int i = 1; i< stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        }else{
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }

        s.push(i);
    }

    for(int i = 0; i< span.size(); i++){
        cout<< span[i]<< " ";
    }
}

void nextGreaterElement(vector<int> arr, vector<int> &ans){     // TC = O(n)
    stack<int> s;
    int n = arr.size();
    ans[n-1] = -1;
    s.push(arr[n-1]);

    for(int i = n-2; i >= 0; i--){
        int currVal = arr[i];
        while(!s.empty() && s.top() <= currVal){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            int nextHigh = s.top();
            ans[i] = nextHigh;
        }

        s.push(currVal);
    }

    for(int i = 0; i< ans.size(); i++){
        cout<< ans[i]<< " ";
    }
}

bool validParenthesis(string str){  // TC =  O(n), SC = O(n)
    stack<char> s;
    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }

        if(ch == ')' || ch == '}' || ch == ']'){
            if(s.empty()){  // Insufficient opening bracket
                return false;
            }
            char top = s.top();
            if((top == '(' && ch == ')') || 
               (top == '{' && ch == '}') || 
               (top == '[' && ch == ']'))
            {
                s.pop();
                continue;
            }else{
                return false;
            }
        }
    }

    if(s.empty()){
        cout<< "Valid Parenthesis \n";
        return true;
    }else{  // Insufficient closing bracket
        cout<< "Invalid Parenthesis \n";
        return false;
    }
    
}

bool isDuplicateParenthesis(string str){
    stack<char> s;

    for(int i = 0; i< str.size(); i++){     //TC = O(n), SC = O(n)
        char ch = str[i];
        
        if(ch != ')'){
            s.push(ch);
        } else{
            if(s.top() == '(' ){
                cout<< "Duplicate Parenthesis \n";
                return true;
            }

            while(s.top() != '('){
                s.pop();
            }
            s.pop();
        }
    }

    cout<< "No duplicate parenthesis \n";
    return false;
}

int maxAreaHistogram(vector<int> heights){   // TC = O(n)
    int n = heights.size();
    vector<int> nls(n);    // Next Left Smaller
    vector<int> nrs(n);    // Next Right Smaller
    stack<int> s;
   
    // Next Left Smaller
    s.push(0);
    nls[0] = -1;
    for(int i = 1; i< n; i++){
        int currVal = heights[i];
        while(!s.empty() && heights[s.top()] >= currVal){
            s.pop();
        }

        if(s.empty()){
            nls[i] = -1;
        } else{
            nls[i] = s.top();
        }

        s.push(i);
    }

    // Vacate the stack for use in 2nd 
    while(!s.empty()){
        s.pop();
    }

    // Next Right Smaller
    nrs[n-1] = n;
    s.push(n-1);
    for(int i = n-2; i >= 0; i--){
        int currVal = heights[i];

        while(!s.empty() && heights[s.top()] >= currVal){
            s.pop();
        }

        if(s.empty()){
            nrs[i] = n;
        } else{
            nrs[i] = s.top();
        }

        s.push(i);
    }

    // Calculate area and maxArea
    int area = 0, maxArea = 0;
    for(int i = 0 ; i < n; i++){
        int width = nrs[i] - nls[i] - 1;
        area = (heights[i] * width);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}


int main(){
/*  // stack implementation using vector
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);

    // while(!s.isEmpty()){
    //     cout<< s.top()<< ' ';
    //     s.pop();
    // }

    tempStack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);

    while(!st.isEmpty()){
        cout<< st.top()<< ' ';
        st.pop();
    }

    tempStack<char> stchar;
    stchar.push('c');
    stchar.push('b');
    stchar.push('a');

    while(!stchar.isEmpty()){
        cout<< stchar.top()<< ' ';
        stchar.pop();
    }

    tempStack<string> stString;
    stString.push("C++");
    stString.push("in");
    stString.push("Learn DSA");

    while(!stString.isEmpty()){
        cout<< stString.top()<< ' ';
        stString.pop();
    }
*/

/*  // stack implementation using Linked List
    tempStackll<int> s2;
    s2.push(3);
    s2.push(2);
    s2.push(1);

    while(!s2.isEmpty()){
        cout<< s2.top()<< ' ';
        s2.pop();
    }
*/

/*  // Push at bottom of stack
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    int val = 4;
    pushAtBottom(s, val);
    while(!s.empty()){
        cout<< s.top()<< ' ';
        s.pop();
    }
*/

    // Reverse a string using stack
    // string str = "abcd";
    // cout<< reverseString(str);

/* // Reverse a stack
   stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    reverseStack(s);
    printStack(s);
*/

/*    // Stock span problem
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    stockSpanProblem(stock, span);
*/

/*    // Next greater element
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};
    nextGreaterElement(arr, ans);
*/

    // // Valid parenthesis
    // string str = "(){}[]";
    // validParenthesis(str);

/*    // Duplicate parenthesis
    string str1 = "((a+b))";
    string str2 = "((a+b) + (c+d))";

    cout<< isDuplicateParenthesis(str1)<< endl;
    cout<< isDuplicateParenthesis(str2)<< endl;
*/

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {2, 1, 5, 6, 7, 3};   
    cout<< "max area = "<< maxAreaHistogram(heights)<< endl;
    cout<< "max area = "<< maxAreaHistogram(heights2)<< endl;


    return 0;
}