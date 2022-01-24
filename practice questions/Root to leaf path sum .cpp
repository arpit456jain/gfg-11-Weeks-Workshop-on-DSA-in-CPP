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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution
{
    public:
    bool hasPathSum(Node *root, int S) {
    // Your code here
    int ans[3];
     ans[0] = 0; // because we are not making the integer global
     ans[1] = S;
     ans[2] = 0;
     int x=0;
     rootToLeaf(root,ans,x);
     if (ans[0] == 0)
        return false;
     else
        return true;
}
void rootToLeaf(Node* root , int ans[],int x)
    {
        // if leaf node
        if(root->left == NULL and root->right == NULL)
        {
            //convert the binary string to int and add it to ans
            
            
            x+= root->data;
            // cout<<x<<"\n";
            if(ans[1] == x)
            ans[0] = 1;
            return;
        }
        
        ans[2] += root->data;
        if(root->left != NULL)
            rootToLeaf(root->left , ans, x+root->data);
            
        
        if(root->right != NULL)
            rootToLeaf(root->right ,ans,x+root->data);
        
        return;
    }
};


// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        Solution ob;
        cout << ob.hasPathSum(root, sum) << "\n";
    }
    return 0;
}
  // } Driver Code Ends