#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int val/* args */) {
        data = val;
        next = NULL;
    }
};

void assigning_linked_list(node* &head){
    head = new node(1);
    node* temp = head;

    for(int i=2 ; i<=6 ; i++){
        temp->next = new node(i);
        temp = temp->next;
    }
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

node* reverse_K_nodes(node* &head,int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* temp = head;
    
    int count = 0;
    while (currptr!=NULL && count<k){
        temp = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = temp;
        count ++;
    }
    if(temp!=NULL){
    head->next = reverse_K_nodes(currptr,k);
    }
    return prevptr;
}

int main(){
    node* head = NULL;
    assigning_linked_list(head);
    display(head);
    cout<<endl;
    node* newhead = reverse_K_nodes(head,2);
    display(newhead);   
    return 0;
}