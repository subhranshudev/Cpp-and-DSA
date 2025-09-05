#include<iostream>
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

class List {
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        //cout<< "~List \n";
        if(head != NULL){
            delete head;
            head = NULL;
        }
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

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data<< " -> ";
            temp = temp->next;
        }
        cout<< "NULL\n";
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i = 0; i< pos-1; i++){
            if(temp == NULL){
                cout<< "Invalid Position \n";
                return;
            }
            temp = temp->next;
        }

        // temp is now at pos-1 i.e prev/left node
        newNode->next = temp->next;
        temp->next = newNode;
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

    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        delete temp->next; // or delete tail;
        temp->next = NULL;
        tail = temp;
    }

    int searchItr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }else{
                temp = temp->next;
                idx++;
            }
        }
        
        return -1;
    }
    int helper(Node* h, int key){
        if(h == NULL){
            return -1;
        }
        if(h->data == key){
            return 0;
        }

        int idx = helper(h->next, key);

        if(idx == -1){
            return -1;
        }
        return idx+1;
    }

    int searchRec(int key){
        return helper(head, key);
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            // updation for next node or iteration
            prev = curr;
            curr = next;
        }

        head = prev; // Important
    }

    int getSize(){
        int size = 0;
        Node* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        cout<<"size = " <<size<<'\n';
        return size;
    }

    void remove(int n){
        int size = getSize();
        Node* prev = head;
        for(int i = 1; i< (size-n); i++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }
     
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList(); // 1->2->3->NULL

    ll.push_back(4);
    ll.push_back(5);
    ll.printList(); // 1->2->3->4->5->NULL

    ll.insert(100, 2);
    ll.printList(); // 1->2->100->3->4->5->NULL

    ll.pop_front();
    ll.printList(); // 2->100->3->4->5->NULL

    ll.pop_back();
    ll.printList(); // 2->100->3->4->NULL

    cout<< ll.searchItr(4)<< endl; // 3

    cout<< ll.searchRec(3)<< endl;

    List ll2;
    ll2.push_back(1);
    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(4);
    ll2.push_back(5);

    ll2.printList(); // 1->2->3->4->5->NULL
    ll2.reverse();
    ll2.printList(); // 5->4->3->2->1->NULL

    ll2.remove(2); // During this "remove" opeartion "reverse" operstion was commented
    ll2.printList(); // 1->2->3->5->NULL

    return 0;
}