I Approach (Using BFS + DP) (Optimal Method)

class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }

    int solve(TreeNode* root, unordered_map<TreeNode*,int> &dp)
    {
        if(root==NULL)
            return 0;

        if(dp.find(root)!=dp.end())
            return dp[root];

        int take=root->val;

        if(root->left)
            take+=solve(root->left->left,dp)+solve(root->left->right,dp);

        if(root->right)
            take+=solve(root->right->left,dp)+solve(root->right->right,dp);

        int notTake=solve(root->left,dp)+solve(root->right,dp);

        return dp[root]=max(take,notTake);
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the number of node's in a given tree 'root'.