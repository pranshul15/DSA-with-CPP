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

void insert_at_head(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}

void insert_at_tail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        insert_at_head(head,val);
        return;
    }
    
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deletion_at_head(node* &head){
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head,int pos){
    int count = 1;
    node* temp = head;
    if(pos == 1){
        deletion_at_head(head);
        return;
    }
    while(count < (pos-1)){
        count ++;
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = todelete->next;
    delete todelete;
}

void display(node* head){
    node* temp = head;
    do
    {   
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);

    display(head);

    deletion(head,1);
    display(head);
    deletion(head,2);
    display(head);
    
    return 0;
}