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

// void merge_ll(node* head1,node* head2){
//     node* ptr1 = head1;
//     node* ptr2 = head2;
//     cout<<"Printing Only"<<endl;
//     while(ptr1 != NULL && ptr2 != NULL){
//         if(ptr1->data > ptr2->data){
//             cout<<ptr2->data<<" ";
//             ptr2 = ptr2->next;
//         }
//         else{
//             cout<<ptr1->data<<"->";
//             ptr1 = ptr1->next;
//         }
//     }
//     cout<<"NULL"<<endl;

//     return;
// }

node* merge_sort_ll(node* head1, node* head2){
    node* dummynode = new node(-1);
    node* p1 = head1;
    node* p2 = head2;
    node* p3 = dummynode;
    while(p1!=NULL and p2!=NULL){
        if(p1->data > p2->data){
            //p2 data is small
            p3->next = p2;
            p2 = p2->next;
        }
        else{
            //p1 data is small
            p3->next = p1;
            p1 = p1->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* merge_sort_rec_ll(node* &head1,node* &head2){
    
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data < head2->data){
        // head1 data is small
        result = head1;
        result->next = merge_sort_rec_ll(head1->next,head2);
    }
    else{
        // head2 data is small
        result = head2;
        result->next = merge_sort_rec_ll(head1,head2->next);
    }
    return result;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,4);
    insert_at_tail(head1,6);
    insert_at_tail(head1,7);
    insert_at_tail(head1,9);

    insert_at_tail(head2,2);
    insert_at_tail(head2,3);
    insert_at_tail(head2,5);
    insert_at_tail(head2,8);

    display(head1);
    display(head2);

    // merge_ll(head1,head2);
    node* newhead = merge_sort_ll(head1,head2);
    display(newhead);
    node* newhead1 = merge_sort_rec_ll(head1,head2);
    display(newhead1);
    return 0;
}