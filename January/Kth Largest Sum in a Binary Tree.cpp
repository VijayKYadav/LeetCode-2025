I Approach (Using Level Order Traversal + MinHeap)

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        while(!q.empty())
        {
            int n=q.size();
            long long sum=0;

            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                sum+=temp->val;

                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);

            }

            minHeap.push(sum);

            if(minHeap.size()>k)
                minHeap.pop();
        }

        if(minHeap.size()<k)
            return -1;
        
        return minHeap.top();
    }
};

Time Complexity: O(n*log(k))
Space Complexity: O(n)
 
where, 'n' is the number of node in a given tree 'root' 
and 'k' is the size of the 'minHeap'.