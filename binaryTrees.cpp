#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
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

int diameter1(Node* root){  // TC = O(n^2)
    if(root == NULL){
        return 0;
    }

    int currDiameter = height(root->left) + height(root->right) + 1;  // O(n)
    int leftDiameter = diameter1(root->left);
    int rightDiameter = diameter1(root->right);

    return max(currDiameter, max(leftDiameter, rightDiameter));
}

pair<int, int> diameter2(Node* root){   // TC = O(n)
    if(root == NULL){
        return make_pair(0, 0);
    }

    // pair(diameter, height)
    pair<int, int> leftInfo = diameter2(root->left);
    pair<int, int> rightInfo = diameter2(root->right);

    int currDiameter = leftInfo.second + rightInfo.second + 1; // leftHeight + rightHeight + 1
    int finalDiameter = max(currDiameter, max(leftInfo.first, rightInfo.first)); // max(currDiameter, max(leftDiameter, rightDiameter));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1; // max(leftHeight, rightHeight) + 1

    return make_pair(finalDiameter, finalHeight);
}

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    } else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return (isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
}

bool isSubtree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    } else if(root == NULL || subRoot == NULL){
        return false;
    }

    if(root->data == subRoot->data){
        // Check Identical or not
        if(isIdentical(root, subRoot)){
            return true;
        }
    }

    int isLeftSubtree = isSubtree(root->left, subRoot);
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }

    return true;
}

void topView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> m;

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();
        
        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node* , int> left = make_pair(currNode->left, currHD-1);
            q.push(left);
        }

        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD + 1);
            q.push(right);
        }
    }

    for(auto it: m){    // In map iteration always occurs from lowest key to highest key
        cout<< it.second<< " ";
    }
    cout<< endl;
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

/*    // Diameter of Tree
    cout<< "Diameter of tree 1 = " << diameter1(root)<< endl;   // TC = O(n^2)
    cout<< "Diameter of tree 2 = " << diameter2(root).first << endl;    // pair(diameter, height); TC = O(n)
*/

/*    // Subtree of another tree
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);
    cout<< isSubtree(root, subRoot)<< endl;
*/

/*    // map
    map<int, string> m;
    m[101] = "Rahul";
    m[110] = "neha";
    m[131] = "Rahul";

    m[101] = "Sekhar";

    cout<< m[101]<< endl;
    cout<< m.count(100) << endl;

    for(auto it: m){
        cout<< "key: " << it.first<< " -> Value: " << it.second<< endl;
    }
*/

    // Top view of tree
    topView(root);


    return 0;
}