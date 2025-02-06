I Approach (Brute Force/Naive Method)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                for(int k=j+1;k<n-1;k++)
                {
                    for(int t=k+1;t<n;t++)
                    {
                        if(solve(nums[i],nums[j],nums[k],nums[t]))
                            ans+=8;
                    }
                }
            }
        }

        return ans;
    }

    bool solve(int a, int b, int c, int d)
    {
        if(a*b==c*d)
            return true;
        
        if(a*c==b*d)
            return true;
        
        if(a*d==b*c)
            return true;
        
        return false;
    }
};

Time Complexity=O(n*n*n*n)
Space Complexity=O(1)

Where, 'n' is the size of the given array 'nums'.
This approach will give Time Limit Exceeded.


II Approach (Optimal Method Using HashMap)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;
        int ans=0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int p=nums[i]*nums[j];
                mp[p]++;
            }
        }

        for(auto it:mp)
        {
            int count=(it.second-1)*it.second/2;
            ans+=8*count;
        }

        return ans;
    }

    
};

Time Complexity=O(n*n)
Space Complexity=O(n*n)

Where, 'n' is the size of the given array 'nums'.

