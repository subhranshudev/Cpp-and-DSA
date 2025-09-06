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

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

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
    
    List ll2;

    ll2.push_front(1);
    ll2.push_front(2);
    ll2.push_front(3);
    ll2.push_front(4);
    ll2.push_front(5);

    printList(ll2.head);
    ll2.head = mergeSort(ll2.head);
    printList(ll2.head);


    return 0;
}