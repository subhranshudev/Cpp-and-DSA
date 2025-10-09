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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHeight = max(leftHeight, rightHeight) + 1;
    return currHeight;
}

static int totalCount = 0;
int nodeCount(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = nodeCount(root->left);
    int rightCount = nodeCount(root->right);

    totalCount = leftCount + rightCount + 1;
    return totalCount;
}

int diameter1(Node* root){  // O(n^2)
    if(root == NULL){
        return 0;
    }

    int currHeight = height(root->left) + height(root->right) + 1;  // O(n)
    int leftDiameter = diameter1(root->left);
    int rightDiameter = diameter1(root->right);

    return max(currHeight, max(leftDiameter, rightDiameter));
}

int main(){
   // Build Tree from Preorder --> Time Complexity = O(n); n = size of preroder
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    // cout<< root->data<< endl;


/*    // Tree Traversal
    preorder(root);
    inorder(root);
    postorder(root);
    levelorder(root);
*/

/*    // Height of a Tree
    vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node* root2 = buildTree(nodes2);
    cout<< root2->data<< endl;
    cout<< "Tree Height = " << height(root2);
*/

    // Count of Nodes
    //cout << "Total Nodes = "<< nodeCount(root2)<< endl;

    // Diameter of Tree
    cout<< "Diameter of tree = " << diameter1(root)<< endl;

    return 0;
}