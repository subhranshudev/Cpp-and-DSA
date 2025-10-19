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

void kThHelper(Node* root, int k, int level){   //O(n)
    if(root == NULL){
        return;
    }

    if(level == k){
        cout<< root->data<< " ";
        return;
    }

    kThHelper(root->left, k, level+1); // Don't do level++ 
    kThHelper(root->right, k, level+1);
}
void kThLevel(Node* root, int k){   // O(n)-> because of helper function
    kThHelper(root, k, 1);
}

bool rootToNodePath(Node* root, int n, vector<int>& path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}
int LCA(Node* root, int n1, int n2){  //  TC = O(n), SC = O(n)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);    
    rootToNodePath(root, n2, path2);  
    
    int lca = -1;
    for(int i = 0, j = 0; i< path1.size(), j < path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }

        lca = path1[i];
    }
    
    return lca;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1,  n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* root, int n){
    if(root == NULL){
        return -1;
    }

    if(root->data == n){    // When we get the node which we were searching for using the value, at that time distance will be zero because we are currently present on that node. Then we return towards LCA and increment distance by 1
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1){ // When we get the required node in left, return towards LCA and increment distance by 1
        return leftDist + 1;
    }

    // If we do not get required node in left, then search in right
    int rightDist = dist(root->right, n);
    if(rightDist != -1){    // When we get the required node in right, return towards LCA and increment distance by 1
        return rightDist + 1;
    }

    return -1;  // If we do not find required node on both sides return -1
}
int minDistance(Node* root, int n1, int n2){    // TC = O(n)
    Node* lca = LCA2(root, n1, n2); // O(n)

    int dist1 = dist(lca, n1);  // O(n)
    int dist2 = dist(lca, n2);  // O(n)

    return dist1 + dist2;
}

int kThAncestor(Node* root, int node, int k){
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDistance = kThAncestor(root->left, node, k);
    int rightDistance = kThAncestor(root->right, node, k);
    
    if(leftDistance == -1 && rightDistance == -1){
        return -1;
    }

    int validValue = leftDistance == -1 ? rightDistance : leftDistance;
    if((validValue + 1) == k){
        cout<< k<< "th Ancestor = " << root->data<< endl;
    }

    return validValue + 1;
}

int transform(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;
    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }

    return currOld;
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
    //topView(root);

    // k th level of tree
    // kThLevel(root, 2);

/*    // Lowest Common Ancestor --> TC = O(n), SC = O(n)
    int n1 = 4, n2 = 6;
    cout<< "LCA = " << LCA(root, n1, n2)<< endl;
    cout<< "LCA2 = " << LCA2(root, n1, n2)->data<< endl;
*/

/*    // Minimum distance between two nodes
    int n1 = 5, n2 = 3;
    cout<< "Min distance = "<< minDistance(root, n1, n2);
*/

/*    int node = 6, k = 1;
    kThAncestor(root, node, k);
*/

    // Transform to Sum Tree
    transform(root);
    levelorder(root);   // Print the tree after transformation
    
    return 0;
}