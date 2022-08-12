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

void insert_at_tail(node* &head,int val){
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

int length_LL(node* head){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;

        count ++;
    }
    return count;
}

void intersect_LL(node* head1,node* head2,int pos){
    node* temp1 = head1;
    node* temp2 = head2;
    int count = 1;
    while(count < pos){
        temp1 = temp1->next;
        count ++;
    }
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void intersect_position(node* head1 , node* head2){
    node* ptr1;
    node* ptr2;
    int l1 = length_LL(head1);
    int l2 = length_LL(head2);
    if(l1 > l2){
        ptr1 = head1;
        ptr2 = head2;
        for(int i=0;i<(l1-l2);i++){
            ptr1 = ptr1->next;
        }
    }
    else{
        ptr1 = head2;
        ptr2 = head1;
        for(int i=0;i<(l2-l1);i++){
            ptr1 = ptr1->next;
        }
    }
    int itr = min(l1,l2);
    for(int i=0;i<itr;i++){
        if(ptr1->next == ptr2->next){
            cout<<"intersecting at "<<ptr1->next->data<<endl;
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    cout<<"non intersecting "<<endl;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    insert_at_tail(head1,5);
    insert_at_tail(head1,6);

    insert_at_tail(head2,7);
    insert_at_tail(head2,8);
    insert_at_tail(head2,9);
    
    display(head1);
    display(head2);

    //intersect_LL(head1,head2,5);
    intersect_position(head1,head2);
    display(head2);
    return 0;
}