I Approach (Using BFS and Unordered_Set of Integer Data_Types)

class FindElements {
private:
    TreeNode* rootN;
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        rootN=root;
        rootN->val=0;

        queue<TreeNode*> q;
        q.push(rootN);
        st.insert(0);

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left)
                {
                    node->left->val=2*node->val+1;
                    st.insert(2*node->val+1);
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    node->right->val=2*node->val+2;
                    st.insert(2*node->val+2);
                    q.push(node->right);
                }
            }
        }
    }
    
    bool find(int target) {
        if(st.find(target)!=st.end())
            return true;

        return false;
    }
};

Time Complexity=O(log(n)) for find Operation .
Space Complexity=O(n).

Where, 'n' is the number of the node in a given tree 'root'.