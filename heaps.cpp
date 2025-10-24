#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Heap{
    vector<int> vec;    // max heap
public:
    void push(int val){
        vec.push_back(val);

        int childIdx = vec.size() - 1;
        int parentIdx = (childIdx - 1) / 2;

        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]){    // O(logn)
            swap(vec[childIdx], vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx - 1)/2;
        }
    }

    void heapify(int parentIdx){
        if(parentIdx >= vec.size()){
            return;
        }

        int leftChild = (parentIdx * 2) + 1;    // Index of left child
        int rightChild = (parentIdx * 2) + 2;   // Index of right child
        
        int maxIdx = parentIdx; // The idx having max value
        if(leftChild < vec.size() && vec[leftChild] > vec[maxIdx]){
            maxIdx = leftChild;
        }

        if(rightChild < vec.size() && vec[rightChild] > vec[maxIdx]){
            maxIdx = rightChild;
        }

        swap(vec[parentIdx], vec[maxIdx]);
        if(parentIdx != maxIdx){
            heapify(maxIdx);
        }
    }

    void pop(){
        // step 1
        swap(vec[0], vec[vec.size() - 1]);
        // step 2
        vec.pop_back();
        // step 3
        heapify(0);
    }

    int top(){
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
/*    priority_queue<int> pq; // By default max heap implemented
    pq.push(5);
    pq.push(10);
    pq.push(3);

    cout<< pq.top()<< endl;
    while(!pq.empty()){
        cout<< pq.top()<< " ";
        pq.pop();
    }
    cout<< endl;

    priority_queue<int, vector<int>, greater<int>> pq2; //  min heap implemented
    pq2.push(9);
    pq2.push(10);
    pq2.push(7);
    pq2.push(5);
    pq2.push(6);
    while(!pq2.empty()){
        cout<< pq2.top()<< " ";
        pq2.pop();
    }
    cout<< endl;

    priority_queue<string> pqs; // Priortity queue of strings
    pqs.push("helloworld");
    pqs.push("apnacollege");
    pqs.push("c++");
    pqs.push("alpha");
    while(!pqs.empty()){
        cout<< pqs.top()<< " ";
        pqs.pop();
        cout<< endl;
    }
*/    

    // Heap
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    cout<< heap.top() << " ";
    while(!heap.empty()){
        cout<< heap.top()<< " ";
        heap.pop();
    }


    return 0;
}