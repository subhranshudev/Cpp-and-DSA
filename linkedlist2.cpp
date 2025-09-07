#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        //cout<<"~Node with value "<< data << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); // dynamic

        if(head == NULL){
            head = tail =  newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front(){
        if(head == NULL){
            cout<<"LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next= NULL;
        delete temp;
    }
};

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data<< " -> ";
        temp = temp->next;
    }
    cout<< "NULL\n";
}

bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            cout<< "Cycle exists \n";
            return true;
        }
    }
    cout<< "Cycle doesn't exist \n";
    return false;
}

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<< "cycle exists \n";
            isCycle = true;
            break;
        }
    }

    if(!isCycle){
        cout<< "cycle doesn't exist \n";
        return;
    }

    slow = head;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
        cout<< "cycle removed, corner case \n";
    } else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
        cout<< "cycle removed \n";
    }
}

void PrintList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<< (*itr)<< " ";
    }
    cout<< '\n';
}

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL;
    }

    return slow; // slow = rightHead
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        } else{
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);   // left = head of left sorted LL
    Node* right = mergeSort(rightHead); // right = head of right sorted LL

    return merge(left, right);
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* revRightHead = reverse(rightHead);

    Node* left = head;
    Node* right = revRightHead;
    Node* tail = right;
    
    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        // updation for next iteration
        left = nextLeft;
        tail = right;
        right = nextRight;
    }

    if(right != NULL){  // For odd sized Linked List
        tail->next = right;
    }

    return head;
}

class DoublyNode{
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
public:
    DoublyNode* head;
    DoublyNode* tail;
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
       DoublyNode* newNode = new DoublyNode(val);
       
       if(head == NULL){
        head = tail = newNode;
       }else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
       }
    }

    void pop_front(){
        DoublyNode* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void printList(){
        DoublyNode* temp = head;
        while(temp != NULL){
            cout<< temp->data<< " <=> ";
            temp = temp->next;
        }
        cout<< "NULL \n";
    }

};

int main(){
/*    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;    // 1->2->3->4->2
    //isCycle(ll.head);

    removeCycle(ll.head);
    printList(ll.head);
*/

/* // Using STL (list, iterator)-------->

    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    PrintList(ll);
    cout<< ll.size()<< endl; 
    
    cout<< "head = "<< ll.front()<< endl;
    cout<< "tail = "<< ll.back() << endl;

    ll.pop_front();
    PrintList(ll);

    ll.pop_back();
    PrintList(ll);

    list<int> my_ll = {5, 6, 7, 8};
    PrintList(my_ll);
    list<int>::iterator itr = my_ll.begin();
    advance(itr, 2); // indexing starts from 0 ; advance() is a utility function used to modify an iterator by moving it forward or backward by a specifed number of positions
    my_ll.insert(itr, 3, 9); // insert(position, number of elements to insert(optional), value to insert)
    PrintList(my_ll);
*/

/*  //Merge Sort
    List ll2;

    ll2.push_front(1);
    ll2.push_front(2);
    ll2.push_front(3);
    ll2.push_front(4);
    ll2.push_front(5);

    printList(ll2.head);
    ll2.head = mergeSort(ll2.head);
    printList(ll2.head);
*/

/*    // Zig Zag Linked List
    List ll3;
    ll3.push_back(1);
    ll3.push_back(2);
    ll3.push_back(3);
    ll3.push_back(4);
    ll3.push_back(5);
    printList(ll3.head);

    ll3.head = zigZagLL(ll3.head);
    printList(ll3.head);
*/
    
    // Doubly Linked List
    DoublyList dbll;
    dbll.push_front(5);
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printList();

    dbll.pop_front();
    dbll.printList();
    

    return 0;
}