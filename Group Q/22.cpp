#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(){
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    
    void add(int val){
        Node* toAdd = new Node();
        toAdd->val = val;
        if(head == NULL){
            head = toAdd;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = toAdd;
    }

    void createCycle(){
        if(head==NULL){return;}

        Node* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = head;
    }

    bool detectCycle(){
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
                if(slow == fast){
                    return true;
                }
            slow = slow->next;
            fast = fast->next->next;
        }
    return false;
    }

    void reverseList(){
        Node *previous = NULL;
        Node *current = head;
        Node *temp;
        while(current!=NULL){
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        head = previous;
    return;
    }

    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    ~LinkedList(){
        if(head == NULL) return;
        if(head->next == NULL) {
            delete head;
            return;
        }
        Node* ptr = head->next;
        while(ptr != NULL && ptr != head){
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        delete head;
    }
};

int main(){
    LinkedList ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    
    ll.printList();
    ll.reverseList();
    ll.printList();

    if(ll.detectCycle()) {cout<<"Cycle Exists"<<endl ;}
    else {cout<<"Cycle does not Exits"<<endl;}
    ll.createCycle();
    if(ll.detectCycle()) {cout<<"Cycle Exists " ;}
    else {cout<<"Cycle does not Exits ";}

    return 0;
}