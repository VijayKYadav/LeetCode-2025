I Approach (Using Recursion)

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preI=0;
        int postI=0;
        return solve(preI,postI,preorder,postorder);
    }

    TreeNode* solve(int &preI, int &postI, vector<int> &preorder, vector<int> &postorder)
    {
        TreeNode* node=new TreeNode(preorder[preI]);
        preI++;

        if(node->val!=postorder[postI]) 
            node->left=solve(preI, postI, preorder, postorder);

        if(node->val!=postorder[postI])
            node->right=solve(preI, postI, preorder, postorder);

        postI++;
        
        return node;
    }

};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'preorder' or 'postorder'.