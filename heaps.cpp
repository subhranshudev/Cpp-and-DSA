#include<iostream>
#include<queue>
#include<vector>
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

void heapify(int parentIdx, vector<int> &vec, int n){   // O(log n)
        int leftChild = (parentIdx * 2) + 1;    // Index of left child
        int rightChild = (parentIdx * 2) + 2;   // Index of right child
        int maxIdx = parentIdx; // The idx having max value

        if(leftChild < n && vec[leftChild] > vec[maxIdx]){
            maxIdx = leftChild;
        }

        if(rightChild < n && vec[rightChild] > vec[maxIdx]){
            maxIdx = rightChild;
        }

        if(parentIdx != maxIdx){
            swap(vec[parentIdx], vec[maxIdx]);
            heapify(maxIdx, vec, n);
        }
    }

void heapSort(vector<int> &arr){
    int n = arr.size();

    // step-1
    for(int i = n/2 - 1; i >= 0; i--){  // O(n log n)
        heapify(i, arr, n);
    }

    // step - 2
    for(int i = n-1; i >= 0; i--){  // O(n log n)
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

class Car{
public: 
    int idx;
    int distSq;
    Car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq;
    }
};
void nearestCars(vector<pair<int, int>> position, int k){
    vector<Car> cars;

    for(int i = 0; i< position.size(); i++){    // Here we can store the car directly in PQ inside loop. But in that case the TC will become O(n logn). push operation TC=O(logn) and for pushing n elements total TC=O(n logn) 
        int x = position[i].first;              // TC=O(n)
        int y = position[i].second;
        int distSq = (x*x) + (y*y);
        
        cars.push_back(Car(i, distSq)); 
    }

    priority_queue<Car> pq(cars.begin(), cars.end());   // TC=O(n); If we will use loop to store elements from vector to PQ, it will take O(nlogn) time. Same above reason

    for(int i = 0; i< k; i++){  // TC=O(k logn)
        cout<< "Car " << pq.top().idx <<endl;    // O(1)
        pq.pop();   // O(log n)
    }
}

int connectRopes(vector<int> ropes){
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());
    int minCost = 0;
    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        minCost += min1 + min2;
        pq.push(min1 + min2);
    }

    cout<< "Minimum cost = " << minCost<< endl;
    return minCost;
}

class Row{
public:
    int count;  // soldier count
    int idx;    // Index of row

    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {
        if(this->count == obj.count){
            return this->idx > obj.idx; // if soldier count become same then compare w.r.t idx
        }
        return this->count > obj.count;
    }
};
void weakestSoldier(vector<vector<int>> matrix, int k){
    vector<Row> rows;

    for(int i = 0; i< matrix.size(); i++){  // visit each row
        int count = 0;
        for(int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++){ // visit every element of the row, if element == 1 increase the soldier count
            count++;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i = 0; i < k; i++){
        cout<< "Row "<< pq.top().idx<< endl;
        pq.pop();
    }
}

void slidingWindow(vector<int> arr, int k){
    priority_queue<pair<int, int>> pq;

    // 1st window
    for(int i = 0; i< k; i++){
        pq.push(make_pair(arr[i], i));
    }

    cout<< "output: "<< pq.top().first<< " ";
    
    for(int i = k; i< arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i-k)){
            pq.pop();
        }

        pq.push(make_pair(arr[i], i));
        cout<< pq.top().first<< " ";
    }
    cout<< endl;
}

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

/*    // Heap
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    cout<< heap.top() << " ";
    while(!heap.empty()){
        cout<< heap.top()<< " ";
        heap.pop();
    }
*/

/*    // Heap sort
    vector<int> arr = {1, 4, 2, 3, 5};
    heapSort(arr);
    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i]<< " ";
    }
*/

/*    // K nearby cars
    vector<pair<int, int>> positions;
    positions.push_back(make_pair(3, 3));
    positions.push_back(make_pair(5, -1));
    positions.push_back(make_pair(-2, 4));

    int k = 2;
    nearestCars(positions, k);
*/

/*    // Connect N ropes
    vector<int> ropes = {4, 3, 2, 6};
    connectRopes(ropes);
*/

   // Weakest Soldier
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 1, 1},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0}};
    int k = 2;
    weakestSoldier(matrix, k);


    // Sliding Window Maximum
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    slidingWindow(arr, k);



    return 0;
}