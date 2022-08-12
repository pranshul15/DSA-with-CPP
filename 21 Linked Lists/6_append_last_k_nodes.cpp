#include <iostream>
using namespace std;

//attach last k nodes of linked list to the first

class node
{
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insert_at_tail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int length (node* head){
    node* temp = head;
    int count =0;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}

node* append_last_k(node* head, int k){
    node* tail = head;
    node* newTail;
    node* newHead;
    int pos = length(head)-k;
    int count=1;
    while(tail->next!=NULL){
        if(count == pos){
            newTail = tail;
            newHead = tail->next;
        }
        count ++;
        tail = tail->next;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main(){
    node* head = NULL;
    for(int i=1;i<=6;i++){
        insert_at_tail(head,i);
    }
    display(head);
    node* newhead = append_last_k(head,3);
    display(newhead);
    return 0;
}