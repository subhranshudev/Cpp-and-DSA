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

 // Using STL (list, iterator)-------->

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

    return 0;
}