#include<iostream>
#include<vector>
#include<string>
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

int main(){
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

    return 0;
}