// Given a quadratic equation in the form ax2 + bx + c. Find its roots.
// Note: Return the maximum root followed by the minimum root.
/*
Input:
a = 1
b = -2
c = 1
Output: 1 1
Explanation:
Roots of equation x2-2x+1 are 1 and 1.
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
          vector<int> roots;
          double D = ((b*b) - (4*a*c));
          cout<<D<<endl;
          if (D<0)
          {
              roots.push_back(-1);
          }
          else
          {
              cout<<"-b is"<<-b<<endl;
              cout<<"sqrt(D)"<<sqrt(D)<<endl;   
              double root1 = floor((-b + sqrt(D))/(2*a));
              double root2 = floor((-b - sqrt(D))/(2*a));
              cout<<"root1 is"<<root1<<"\nroot2 is"<<root2<<endl;
            
            if(root1>root2)
            {
             roots.push_back(root1);
             roots.push_back(root2);
            }
            else 
            {
                roots.push_back(root2);
             roots.push_back(root1);

            }
          }

          return roots;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

// Testcases
/*
1
1 -2 1
*/