#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Build Tree from Preorder
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

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);  // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

// Tree Traversal
void preorder(Node* root){  // TC=O(n), SC=O(n)
    if(root == NULL){
        return;
    }

    cout<< root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){   // TC = O(n)
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data<< " ";
    inorder(root->right);
}

void postorder(Node* root){ // TC = O(n)    
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<< " ";
}

void levelorder(Node* root){    // TC = O(n), SC = O(n)
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout<< endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        } else{
            cout<< curr->data<< " ";

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

int main(){
    // Build Tree from Preorder --> Time Complexity = O(n); n = size of preroder
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    cout<< root->data<< endl;

    // Tree Traversal
    preorder(root);
    inorder(root);
    postorder(root);
    levelorder(root);

    return 0;
}