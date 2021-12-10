// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* optimisedApproch(struct Node *head)
    {
        // logic is to reverse the link between the nodes
        struct Node* prev ,*current,*next;
        prev = NULL;
        next = NULL;
        current = head;
        while(current!=NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    struct Node* reverseList(struct Node *head)
    {
        return optimisedApproch(head);
    }

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
             Solution ob;
        first = ob. reverseList(first);
        second = ob.reverseList(second);
        int carry = 0;
        Node *temp1=first;
        Node *temp2=second;
        Node *head = new Node(-1);
        Node *curr = head;
        int sum1=0;
        while(temp1!=NULL && temp2!=NULL)
        {

            sum1 = temp1->data  + temp2->data + carry;
            
            if(sum1>=10)
            {
                sum1 = sum1%10;
                carry = 1;
            }
            else
            carry=0;
            Node *newnode = new Node(sum1);
           
            curr->next = newnode;
            curr= curr->next;
            // cout<<curr->data<<"\n";
            
            //move the pointer on both list
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            sum1 = temp1->data + carry;
            
            if(sum1>=10)
            {
                sum1 = sum1%10;
                carry = 1;
            }
            else
            carry=0;
            Node *newnode = new Node(sum1);
            curr->next = newnode;
            curr= curr->next;
            temp1 = temp1->next;

        }
        while(temp2!=NULL)
        {
            sum1 = temp2->data + carry;
            
            if(sum1>=10)
            {
                sum1 = sum1%10;
                carry = 1;
            }
            else
            carry=0;
            Node *newnode = new Node(sum1);
            curr->next = newnode;
            curr= curr->next;
            temp2 = temp2->next;

        }
        if(carry==1)
        {
            Node *newnode = new Node(1);
            curr->next = newnode;
            curr= curr->next;
        }
    head = head->next;
    head = ob.reverseList(head);
    return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends