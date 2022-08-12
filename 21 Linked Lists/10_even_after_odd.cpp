#include <iostream>
using namespace std;

class node
{
private:
    /* data */
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

void odd_before_even(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenstart = even;
    while(odd->next != NULL and odd->next->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
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
    for(int i=1;i<=6;i++){
        insert_at_tail(head,i);
    }
    display(head);
    odd_before_even(head);
    display(head);
    return 0;
}