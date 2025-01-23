I Approach (Using PreOrder Traversal)

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        solve(root,0,ans);
        return ans;
    }

    void solve(TreeNode* root, int val,int &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            ans=ans+2*val+root->val;
            return ;
        }
        
        solve(root->left,2*val+root->val,ans);
        solve(root->right,2*val+root->val,ans);
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of node's in a given tree'root'.
