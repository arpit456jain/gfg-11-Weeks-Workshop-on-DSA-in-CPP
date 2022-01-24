// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution
{
    public:
    void swapPointers(Node* root) {
        //swap the pointers
         if(root == NULL)
             return;
    
       
        // recursive call
        swapPointers(root->left);
        swapPointers(root->right);
      
        Node* temp = root->left;
            root->left = root->right;
            root->right = temp; 
           
    }
    void mirror(Node* node) {
        // code here
         if(node == NULL)
            return;
        
        swapPointers(node);
        
    }
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        return check(r1,r2);
    }
    bool check(Node *r1, Node *r2)
    {
        if(r1 == NULL and r2 == NULL)
        return true;
        
        if(r1 == NULL or r2 == NULL)
        return false;
        
        bool c1 = check(r1->left,r2->left);
        bool c2 = check(r1->right,r2->right);
        
        if(c1 and c2 and r1->data == r2->data)
        return true;
        else
        return false;
    }
    int areMirror(Node* a, Node* b) {
    // Your code here
    // step1 : make mirror tree
        mirror(a);
    // step 2: check if its identical or not
        return isIdentical(a,b);
    }

};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        Solution ob;
        cout << ob.areMirror(root1, root2) << "\n";
    }
    return 0;
}  // } Driver Code Ends