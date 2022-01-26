#include<iostream>
using namespace std;

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
class linked_list
{
private:
node* head;
public:
    
    linked_list() {
        head = NULL;
    }

    void add(int val){
        node* n = new node(val);
        
        if(head == NULL){
            head = n;
            return;
        }

        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
    }

    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int length(node* &head){
        node* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
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

    void reverse_ll(int k){
        head = reverse_K_nodes(head,k);
    }
};


int main(){
    linked_list ll;
    ll.add(11);
    ll.add(2);
    ll.add(32);
    ll.add(4);
    ll.add(10);
    ll.print();
    ll.reverse_ll(3);
    ll.print();

    return 0;
}