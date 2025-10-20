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

bool search(Node* root, int key){   // TC = O(height) 
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key < root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }else if(val> root->data){
        root->right = deleteNode(root->right, val);
    }else{
        // root == val
        // case-1: Leaf Node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case-2: One Child
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        // Case-3: Two Children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
    }

    return root;
}

void printINRange(Node* root, int start, int end){
    if(root == NULL){
        return;
    }
    if(start <= root->data && root->data <= end){
        cout<< root->data << " ";
        printINRange(root->left, start, end);
        printINRange(root->right, start, end);
    }else if(root->data < start){
        printINRange(root->right, start, end);
    }else{
        printINRange(root->left, start, end);
    }
}

int main(){
    //Build BST
    int arr[] = {5, 1, 3, 4, 2, 7};
    int arr2[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBst(arr2, 9);
    inorder(root);
    cout<< endl;

    // Search in BST
    //cout<< search(root, 6)<< endl;

    // Delete Node in BST
    // deleteNode(root, 5);
    // inorder(root);

    // Print in range
    printINRange(root, 5, 12);


    return 0;
}