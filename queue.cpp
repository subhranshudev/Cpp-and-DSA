#include<iostream>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

// Implementaion of circular Queue
class Queue{
    int* arr;

    int capacity;
    int currSize;
    
    int f, r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data){
        if(currSize == capacity){
            cout<< "Queue is full \n";
            return;
        }

        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<< "Queue is empty \n";
            return;
        }

        f = (f+1) % capacity;
        currSize--;
    }

    int front(){
        if(empty()){
            cout<< "Queue is empty \n";
            return -1;
        }

        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printRear(){
        cout<< arr[r]<< endl;
    }

};

// Queue implementation using 2 stacks
class QueueS{
    stack<int> s1;
    stack<int> s2;
public: 

    void push(int data){
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        //  s2 -> s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

// Stack implementation using 2 Queues
class Stack{
    queue<int> q1;
    queue<int> q2;
public: 
    void push(int data){
        // q1 -> q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        // q2 -> q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        q1.pop();
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

// First non-repeating character
void firstNonRepeatingChar(string str){
    int n = str.size();
    int freq[26] = {0};
    queue<char> Q;

    for(int i = 0; i< n; i++){
        char ch = str[i];
        Q.push(ch);
        int idx = ch - 'a';
        freq[idx]++;

        while(!Q.empty() && freq[Q.front() - 'a'] > 1){
            Q.pop();
        }

        if(Q.empty()){
            cout<< "-1 ";
        }else{
            cout<< Q.front()<< " ";
        }
    }
}

void interleave(queue<int> &original){ // TC = O(n), SC = O(n)
    queue<int> firstHalf;
    int n = original.size();

    while(original.size() > n/2){
        firstHalf.push(original.front());
        original.pop();
    }

    while(!firstHalf.empty()){
        original.push(firstHalf.front());
        original.push(original.front());

        firstHalf.pop();
        original.pop();
    }
}

void printQueue(queue<int> Q){
    while(!Q.empty()){
        cout<< Q.front()<< " ";
        Q.pop();
    }
    cout<< endl;
}

void queueReversal(queue<int> &Q){
    stack<int> s;
    while(!Q.empty()){
        s.push(Q.front());
        Q.pop();
    }

    while(!s.empty()){
        Q.push(s.top());
        s.pop();
    }
}

class queueD{
    deque<int> deq;
public:
    void push(int data){
        deq.push_back(data);
    }

    void pop(){
        deq.pop_front();
    }

    int front(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};

int main(){
/*  // Circular Queue Implementation
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<< q.front() << endl;
    q.printRear(); 
    q.pop();
    cout<< q.front()<< endl;
    q.push(5);
    cout<< q.front()<< endl;
    q.printRear();
*/

/*    // queue in STL
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<< q.front()<< " ";
        q.pop();
    }
*/

/*    // Queue using 2 Stacks
    QueueS q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<< q.front()<< " ";
        q.pop();
    }
*/

/*    // Stack using 2 Queues
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<< s.top()<< " ";
        s.pop();
    }
*/

/*    // First non-repeating character
    string str = "aabccxb";
    firstNonRepeatingChar(str);
*/

/*    // Interleave Queue
    queue<int> original;
    for(int i = 1; i<= 10; i++){
        original.push(i);
    }
    printQueue(original);

    interleave(original);
    printQueue(original);
*/

/*    // Queue Reversal
    queue<int> Q;
    for(int i = 1; i<= 5; i++){
        Q.push(i);
    }
    printQueue(Q);
    queueReversal(Q);
    printQueue(Q);
*/

/*    // Double Ended Queue (deque)
    deque<int> deq;
    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);

    // 1 2 3 4
    deq.pop_front(); // 2 3 4
    deq.pop_back(); // 2 3

    cout<< deq.front();
    cout<< deq.back();
*/

    // Queue implementation using deque
    queueD Q;
    for(int i = 1; i<=5; i++){
        Q.push(i);
    }

    while(!Q.empty()){
        cout<< Q.front()<< " ";
        Q.pop();
    }
    return 0;
}