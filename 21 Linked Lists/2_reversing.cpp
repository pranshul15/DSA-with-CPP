#include <iostream>
using namespace std;

class node
{    
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void assigning_linked_list(node* &head){
    head = new node(1);
    node *temp = head;
    for(int i=2;i<=8;i++){
        temp->next = new node(i);
        temp = temp->next;
    }
}

node* reverse(node* &head){
    node *previous = NULL;
    node *current = head;
    node *temp;
    while(current!=NULL){
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    return previous;
}

node* reverse_recursive(node* &head){
    
    if(head == NULL or head->next==NULL){
        return head;
    }

    node* newhead = reverse_recursive(head->next);
    head->next->next = head;
    head->next=NULL;
    return newhead;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    assigning_linked_list(head);
    display(head);
    node* newhead = reverse_recursive(head);
    display(newhead);
    return 0;
}