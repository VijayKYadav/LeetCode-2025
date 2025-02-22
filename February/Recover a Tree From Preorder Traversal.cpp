I Approach (Using Recursion and String Manipulation)

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.length();
        int ind=0;
        return solve(ind,n,traversal,0);
    }

    TreeNode* solve(int &ind, int n, string &s, int depth)
    {
        if(ind==n)
            return NULL;

        int d=0;
        while(ind+d<n && s[ind+d]=='-')
            d++;
        
        if(d!=depth)
            return NULL;

        ind+=d;
        int val=0;
        while (ind<n && isdigit(s[ind])) 
        {
            val=val*10+(s[ind]-'0');
            ind++;
        }

        TreeNode* node=new TreeNode(val);

        node->left=solve(ind,n,s,depth+1);
        node->right=solve(ind,n,s,depth+1);

        return node;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the length of the given string 'traversal'.