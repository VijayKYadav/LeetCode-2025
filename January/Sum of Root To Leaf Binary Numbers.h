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


Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given square matrix 'grid'.

II Approach

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    if(row[i]>=2 || col[j]>=2)
                        count++;
                }
            }
        }

        return count;
    }
};

Time Complexity: O(n)
Space Complexity: O(log(Height of given tree))
 
where, 'n' is the number of node's in a given tree'root'.