I Approach (Using Difference Array Technique) (Optimal Method)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        int sum=0;
        int k=0;
        vector<int> dif(n+1,0);

        for(int i=0;i<n;i++)
        {
            while(sum+dif[i]<nums[i])
            {
                k++;

                if(k>m)
                    return false;
                
                int left = queries[k - 1][0];
                int right = queries[k - 1][1];

                if(right>=i)
                {
                    dif[max(left,i)]+=1;
                    dif[right+1]-=1;
                }
            }
            sum+=dif[i];
        }

        return true;
    }
};

Time Complexity=O(n+m).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums' and
'm' is the size of given 2D-vector 'queries'.