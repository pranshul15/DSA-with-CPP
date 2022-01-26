#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};
void insert_at_head(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
void insert_at_tail(node* &head ,int val){

    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool searching(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;   
        }
        temp=temp->next;
    }
    return false;
}
void delete_at_head(node* &head){
    node*todelete = head;
    head=head->next;
    delete todelete;
  
}
void deletion(node* &head,int key){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    node* temp=head;
    while(temp->next->data != key){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main(){

    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,0);
    insert_at_tail(head,3);
    display(head);
    insert_at_head(head,4);
    display(head);
    cout<<searching(head,3)<<endl;
    deletion(head,0);
    display(head);
    delete_at_head(head);
    display(head);
    return 0;
}