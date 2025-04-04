I Approach (Using Recursion) (Optimal Method)

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* root) 
    {
        if (!root)
            return {nullptr, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second)
            return {left.first, left.second + 1};

        if (left.second < right.second)
            return {right.first, right.second + 1};

        return {root, left.second + 1};
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the number of node's in a given tree 'root'.