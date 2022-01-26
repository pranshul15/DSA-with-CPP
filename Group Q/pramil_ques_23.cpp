# include <bits/stdc++.h>
using namespace std ;

class Node
{
    public:
    int data ;
    Node* next ;

    Node (int val)
    {
        data = val;
        next = NULL ;
    }

};
//-------------------------------------
//function to insert element at tail.
void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val) ;

    if(head == NULL)
    {
        head = n ;
        return ;
    }

    Node* temp = head ;
    while (temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = n ;
}
//--------------------------------------
//function to display elements in linked list 
void display (Node* head )
{
    Node* temp = head ;
    while (temp != NULL)
    {
        cout << temp->data << "->" ;
        temp = temp->next ;
    }
    cout << "NULL\n" ;

}
//----------------------------------------------
//function to get the length of ll.
int getlength(Node* &head)
{
    int count = 0;
    Node* temp = head ;
    while (temp!=NULL)
    {
        temp = temp->next ;
        count++ ;
    }
    return count ;

}
//-----------------------------------------------
//function to reverse first k nodes
Node* reverseK(Node* &head, int k)
{
    Node* prevptr = NULL ;
    Node* currptr = head ;
    Node* nexptr ;
    Node* temp = currptr ;
    for (int i = 0; i < k; i++)
    {
        if(temp == NULL) 
        {
            // head->next = currptr ;
            return currptr ;
        }
        else temp = temp->next ;
        // else head->next = reverseK(nexptr,k) ;
    }
    int count = 0 ;
    while(currptr != NULL && count < k) 
    {
        nexptr = currptr->next ;
        currptr->next = prevptr ;

        prevptr = currptr ;
        currptr = nexptr ;
        count++ ;
    }
    if(nexptr!=NULL)
        head->next = reverseK(nexptr,k) ;
    
    return prevptr ;
    
}
//////////////////////////////////////////////////
int main()
{
    Node* head = NULL ; 
    insertAtTail(head,1) ;
    insertAtTail(head,2) ;
    insertAtTail(head,3) ;
    insertAtTail(head,4) ;
    // insertAtTail(head,10) ;
    // insertAtTail(head,6) ;
    // insertAtTail(head,7) ;
    display(head) ;
    int k ; cin >> k ;
    // int length = getlength(head) ;
    // int max_count = length-(length%k) ;
    Node* newhead = reverseK(head,k) ;
    display(newhead) ;
}