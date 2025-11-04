#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totalSize;
    int currSize;
    Node** table;   // Pointer of Pointer; table is a pointer which will store the reference of an array; and that array will store reference of Nodes

    int hashFunction(string key){
        int idx = 0;

        for(int i = 0; i< key.size(); i++){
            idx = idx + (key[i] * key[i])%totalSize;
        }

        return (idx % totalSize); // it was the reason the error was coming (take modulo by totalSize)
    }

    void rehash(){
        Node** oldTbale = table;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        currSize = 0;
        table = new Node*[totalSize];
        

        for(int i = 0; i< totalSize; i++){
            table[i] = NULL;
        }

        // Copy old value
        for(int i = 0; i< oldSize; i++){
            Node* temp = oldTbale[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTbale[i] != NULL){
                delete oldTbale[i];     // It will only delete the head node. So to delete the all remaining nodes write destructor in Node class
            }
        }

        delete[] oldTbale;
    }

public:
    HashTable(int size=5){
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];   // Create an array dynamically of datatype Node* and size = totalSize

        for(int i = 0; i< totalSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        //Node* head = table[idx];
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totalSize;
        if(lambda > 1){
            rehash();
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
    
    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return temp->val;
            }

            temp = temp->next;
        }

        return -1;
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while(temp != NULL){
            if(temp->key == key){
                if(temp == prev){   // Remove the head node
                    table[idx] = temp->next;
                }else{  // Remove any other node
                    prev->next = temp->next;
                }
                return; 
            }

            prev = temp;
            temp = temp->next;
        }
    }

    void print(){
        for(int i = 0; i< totalSize; i++){
            cout<< "Idx-"<< i<< " -> ";
            Node* temp = table[i];
            while(temp != NULL){
                cout<< "(" << temp->key << "," << temp->val << ") -> " ;
                temp = temp->next;
            }
            cout<< endl;
        }
    }
};

void majorityElement(vector<int> nums){ // TC = O(n) ; In some cases it can be O(n^2) due to rehashing, But very minimum cases
    int n = nums.size();
    unordered_map<int, int> m;

    for(int i = 0; i< n; i++){
        if(m[nums[i]]){
            m[nums[i]]++;
        }else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int, int> p : m){
        if(p.second > n/3){
            cout<< p.first << " ";
        }
    }

    cout<< endl;
}

bool validAnagrams(string str1, string str2){    // TC = O(n)
    if(str1.length() != str2.length()){
        return false;
    }
    
    unordered_map<char, int> freq;

    for(char ch : str1){
        if(freq[ch]){
            freq[ch]++;
        }else{
            freq[ch] = 1;
        }
    }

    for(char ch : str2){
        if(freq[ch]){
            freq[ch]--;
        }else{
            return false;
        }
    }

    return true;
}

int countDistinct(vector<int> arr){
    unordered_set<int> s;

    for(int i = 0; i< arr.size(); i++){
        s.insert(arr[i]);
    }

    for(int el : s){    // Print all the distinct elements
        cout<< el<< " ";
    }
    cout<< endl;

    return s.size();
}

void printUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int el : arr1){
        s.insert(el);
    }

    for(int el : arr2){
        s.insert(el);
    }

    cout<< "Union = ";
    for(int el : s){
        cout<< el << " ";
    }
    cout<< endl;
}

void printInterSection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int el : arr1){
        s.insert(el);
    }

    cout<< "Intersection = ";
    for(int el : arr2){
        if(s.count(el)){
            cout<< el<< " ";
            s.erase(el);
        }
    }
    cout<< endl;
}

void printItinerary(unordered_map<string, string> tickets){
    // Starting point
    unordered_set<string> to;

    for(pair<string, string> ticket : tickets){ // pair<from, to>
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string> ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }

    cout<< start<< " -> ";
    while(tickets.count(start)){
        cout<< tickets[start]<< " -> ";
        start = tickets[start];
    }

    cout<< "Destination \n";
}

int largestSubarraywithSum0(vector<int> arr){
    unordered_map<int, int> m;
    int sum = 0, ans = 0;
    for(int j = 0; j< arr.size(); j++){
        sum += arr[j];

        if(m.count(sum)){
            int currLength = j - m[sum];
            ans = max(ans, currLength);
        }else{
            m[sum] = j;
        }
    }

    return ans;
}

int subarraySumEqualsK(vector<int> arr, int k){
    unordered_map<int, int> m; // m<sum, count>
    m[0] = 1;
    int sum = 0, count = 0;

    for(int j = 0; j< arr.size(); j++){
        sum += arr[j];

        if(m.count(sum-k)){
            count += m[sum-k];
        }

        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }

    return count;
}

int main(){
/*    // Hash Table
    HashTable ht;
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if(ht.exists("India")){
        cout<< "India Population = "<< ht.search("India")<< endl;
    }
    ht.print();
    ht.remove("China");
    ht.print();
*/

/*    // Unordered Map
    unordered_map<string, int> uMap;
    uMap["China"] = 150;
    uMap["India"] = 150;
    uMap["US"] = 50;
    uMap["Nepal"] = 10;

    cout<< "India = " << uMap["India"]<< endl;
    
    for(pair<string, int> country : uMap){
        cout<< country.first << ","<< country.second << endl;
    }

    uMap["India"] = 160;
    cout<< "India = " << uMap["India"]<< endl;

    // if count = 0 => element is not present; if count != 0 => element is present
    if(uMap.count("Nepal")){
        cout<< "Nepal exists" << endl;
    }else{
        cout<< "Nepal doesn't exist"<< endl;
    }

    uMap.erase("Nepal");

    if(uMap.count("Nepal")){
        cout<< "Nepal exists"<< endl;
    }else{
        cout<< "Nepal doesn't exist"<< endl;
    }
*/

/*    // Map
    map<string, int> m;
    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    cout<< "India = " << m["India"]<< endl;
    
    for(pair<string, int> country : m){
        cout<< country.first << ","<< country.second << endl;
    }
*/   

/*    // Unordered Sets --> TC = O(1)
    unordered_set<int> uSet;

    uSet.insert(1);
    uSet.insert(5);
    uSet.insert(3);
    uSet.insert(2);

    cout<< "Size = " << uSet.size()<< endl;

    uSet.insert(5);
    uSet.insert(3);
    cout<< "Size = " << uSet.size()<< endl;

    uSet.erase(3);
    if(uSet.find(3) != uSet.end()){
        cout<< "3 exists"<< endl;
    }else{
        cout<< "3 doesn't exist"<< endl;
    }

    for(auto el : uSet){
        cout<< el<< ", ";
    }
*/

/*    // Set --> TC = O(log n)
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    cout<< "Size = " << s.size()<< endl;

    s.insert(5);
    s.insert(3);
    cout<< "Size = " << s.size()<< endl;

    s.erase(3);
    if(s.find(3) != s.end()){
        cout<< "3 exists"<< endl;
    }else{
        cout<< "3 doesn't exist"<< endl;
    }

     for(auto el : s){
        cout<< el<< ", ";
    }
*/

/*    // Pair Sum
    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7;
    int target = 9;

    unordered_map<int, int> m;
    for(int i = 0; i< n; i++){
        int complement = target - arr[i];
        if(m.count(complement)){
            cout<< "ans = {"<< m[complement] << ","<< i << "}" << endl;
            break;
        }

        m[arr[i]] = i;
    }
*/

/*    // Majority Element
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums2 = {1, 2};

    majorityElement(nums2);
*/

/*    // Valid Anagram
    string str1 = "race";
    string str2 = "care";
    cout<< validAnagrams(str1, str2)<< endl;
*/

/*    // Count Distinct
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
    cout << "Distinct Count = "<< countDistinct(arr) << endl;
*/

/*    // Union and Intersection of sets
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};
    printUnion(arr1, arr2);
    printInterSection(arr1, arr2);
*/

/*    // Itinerary from Tickets
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
*/

/*    // Largest subarray with sum 0
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    cout<< "Largest subarray length with sum 0 = " << largestSubarraywithSum0(arr);
*/

    // Subarray Sum equals k
    vector<int> arr = {1, 2, 3};
    int k = 3;
    cout<< "Subarray sum equals k = " << subarraySumEqualsK(arr, k);

    
    


    return 0;
}