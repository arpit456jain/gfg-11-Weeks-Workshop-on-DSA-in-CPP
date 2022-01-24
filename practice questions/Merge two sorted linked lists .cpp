// { Driver Code Starts
#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* list1, Node* list2)  
{  
    // code here
    if (list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
    Node* head = new Node(-1);
    Node* dummy = head;
    Node* temp1 = list1;
    Node* temp2 = list2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data<temp2->data)
            {
                Node* nextnode = new Node(temp1->data);
                dummy->next = nextnode;
                temp1 = temp1->next;
                // cout<<dummy->data;
            }
            else
            {
                Node* nextnode = new Node(temp2->data);
                dummy->next = nextnode;
                temp2 = temp2->next;
                // cout<<dummy->data;
            }
            dummy=dummy->next;
        }
        if(temp1!=NULL)
            dummy->next = temp1;
        if(temp2!=NULL)
            dummy->next = temp2;
        
        return head->next;
}  