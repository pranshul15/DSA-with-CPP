#include <iostream>
using namespace std;

class node
{
private:
    /* data */
public:
    int data;
    node* next;
    node* previous;
    node(int val) {
        data = val;
        next = NULL;
        previous = NULL;
    }
    
};

void insert_at_head(node* &head,int val){
    
    if(head == NULL){
        head = new node(val);
        return;
    }
    node* n = new node(val);
    n->next = head;
    head->previous = n;
    head = n;
}

void insert_at_tail(node* &head,int val){
    if(head == NULL){
        head = new node(val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->previous = temp;
}

void deletion_at_head(node* &head){
    node* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;

}

void deleteion(node* &head,int key){
    
    node* temp = head;
    while(temp->data != key){
        temp = temp->next;
    }
    if(temp == head){
        deletion_at_head(head);
        return;
    }
    temp->previous->next = temp->next;
    if(temp->next != NULL){
        temp->next->previous = temp->previous;
    }
    
    delete temp;
}

void display (node* &head){
    node* temp = head;
    cout<<"NULL-> ";
    while(temp->next!=NULL){
        cout<<temp->data<<" <=> ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<" <-NULL"<<endl;
}

int main(){
    node* head = NULL;
    for(int  i=1;i<=6;i++){
        insert_at_tail(head,i);
    }
    for(int i=0;i>-6;i--){
        insert_at_head(head,i);
    }
    display(head);
    deleteion(head,-2);
    display(head);
    deletion_at_head(head);
    display(head);
    deleteion(head,6);
    display(head);
    cout<<endl;
    return 0;
}