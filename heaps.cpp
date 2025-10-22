#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    priority_queue<int> pq; // By default max heap implemented
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
    

    return 0;
}