#include <iostream>
using namespace std;

//Floyed's Algorithm

class node
{
private:
    /* data */
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

    for(int i=2;i<=9;i++){
        temp->next = new node(i);
        temp = temp->next;
    }

}

void make_cycle(node* &head , int pos){
    node* temp = head;
    node* startNode;
    int count = 1;

    while(temp->next != NULL){
        if(count = pos){
            startNode = temp;
        }
        count ++;
        temp = temp->next;
    }

    temp->next = startNode;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

bool cycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        if(slow->data = fast->data){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void remove_cycle(node* &head){
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    
}

int main(){
    node* head = NULL;
    assigning_linked_list(head);
    make_cycle(head,6);
    //display(head);
    cout<<cycle(head)<<endl;
    remove_cycle(head);
    display(head);
    cout<<endl;
    return 0;
}