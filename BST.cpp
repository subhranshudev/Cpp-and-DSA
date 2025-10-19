#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    } 
};

Node* insert(Node* root, int val){  // TC = O(log n)
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBst(int arr[], int n){   // TC = O(n)
    Node* root = NULL;
    for(int i = 0; i< n; i++){
        root = insert(root, arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    } 
    inorder(root->left);
    cout<< root->data<< " ";
    inorder(root->right);
}

int main(){
    int arr[] = {5, 1, 3, 4, 2, 7};
    int arr2[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBst(arr2, 9);
    inorder(root);


    return 0;
}