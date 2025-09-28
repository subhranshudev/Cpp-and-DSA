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

void stockSpanProblem(vector<int> stock, vector<int> span){
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


int main(){
/*    // stack implementation using vector
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

/*    tempStackll<int> s2;
    s2.push(3);
    s2.push(2);
    s2.push(1);

    while(!s2.isEmpty()){
        cout<< s2.top()<< ' ';
        s2.pop();
    }
*/

/*    stack<int> s;
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

    // string str = "abcd";
    // cout<< reverseString(str);

/*    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    reverseStack(s);
    printStack(s);
*/

    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    stockSpanProblem(stock, span);

    return 0;
}