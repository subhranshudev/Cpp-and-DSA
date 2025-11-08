#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;   // for Prefix Problem

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        root->freq = -1;    // for Prefix Problem
    }

    void insert(string key){    //TC =  O(L)
        Node* temp = root;

        for(int i = 0; i< key.size(); i++){ // Insert each char of string one by one
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;   // for Prefix Problem
            }else{
                temp->children[key[i]]->freq++; // for Prefix Problem
            }

            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }

        return temp->endOfWord;
    }

    string getPrefix(string key){
        Node* temp = root;
        string prefix = "";

        for(int i = 0; i< key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }

    bool startsWith(string prefix){ // O(L)
        Node* temp = root;

        for(int i = 0; i< prefix.size(); i++){
            if(temp->children.count(prefix[i])){
                temp = temp->children[prefix[i]];
            }else{
                return false;
            }
        }

        return true;
    }

    int countHelper(Node* root){
        int count = 0;

        for(pair<char, Node*> child : root->children){
            count += countHelper(child.second);
        }

        return count + 1; //+1 for empty string ""
    }
    int countNode(){
        return countHelper(root);
    }
};

bool helper(Trie &trie, string key){
    if(key.size() == 0){
        return true;
    }

    for(int i = 0; i < key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }

    return false;
}
bool wordBreak(vector<string> dict, string key){
    Trie trie;
    for(int i = 0; i< dict.size(); i++){
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}

void prefixProblem(vector<string> dict){
    Trie trie;
    for(int i = 0; i< dict.size(); i++){
        trie.insert(dict[i]);
    }

    for(int i = 0; i < dict.size(); i++){
        cout<< trie.getPrefix(dict[i]) << ", ";
    }
    
}

bool startsWithProblem(vector<string> dict, string prefix){
    Trie trie;
    for(int i = 0; i< dict.size(); i++){
        trie.insert(dict[i]);
    }

    return trie.startsWith(prefix);
}

int countUniqueSubstrings(string str){
    Trie trie;
    // Find all the suffixes and craete a trie using all those suffixes
    for(int i = 0; i< str.size(); i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNode();
}

int main(){
/*    // Basics of Trie
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for(int i = 0; i< words.size(); i++){
        trie.insert(words[i]);
    }

    cout<< trie.search("the")<< endl;
*/

/*    // Word Break
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    string key = "ilikesamsung";
    cout<< wordBreak(dict, key) << endl;
*/

/*    // Prefix Problem
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    prefixProblem(words);
*/

/*    // startsWith Problem
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    string prefix = "appe";
    cout<< startsWithProblem(words, prefix);
*/

    // Count Unique Substrings
    string str = "abc";
    cout<< countUniqueSubstrings(str);


    return 0;
}