// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
int getLength(Node* head)
{
    int count=0;
    Node* temp = head;;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
 return count;   
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int length1 = getLength(head1);
    int length2 = getLength(head2);
    
    // cout<<length1<<" "<<length2<<"\n";

    
   
    Node *temp,*temp2;
    
    // run the pointer of longest list
    if(length1 >= length2)
    {
         int difference = length1 - length2;
        // move pointer 1
        temp = head1;
        temp2=head2;
        while(difference>0)
        {
            temp=temp->next;
            difference--;
        }
    }
    else
    {
        // move pomter 2
         int difference = length2 - length1;
        temp = head2;
        temp2 = head1;
        while(difference>0)
        {
            temp=temp->next;
            difference--;
        }
    }
    
    // now both pointers are eqidistant from NULL so run both list until NULL
    // if address coincide break;
    while(temp!=NULL && temp2!=NULL)
    {
        if(temp->next == temp2->next)
        return temp->next->data;
        temp=temp->next;
        temp2=temp2->next;
    }
    return NULL ;
}

