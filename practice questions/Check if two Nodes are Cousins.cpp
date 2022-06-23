if(root == NULL)
            return false;
        if(root->left == NULL and root->right == NULL)
            return false;
        if(root->val == x or root->val == y)
            return false;
        
        int Parentx = -1;
        int Parenty = -1;
        int xHeight = findHeight(root,Parentx,x,0);
        int yHeight = findHeight(root,Parenty,y,0);
        
        if(xHeight == yHeight and Parentx!=Parenty)
            return true;
        return false;