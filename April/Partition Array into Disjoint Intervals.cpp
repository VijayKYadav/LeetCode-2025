I Approach (Using Two Array/Vector)

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxA(n);
        vector<int> minA(n);

        maxA[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxA[i]=max(nums[i],maxA[i-1]);
        }

        minA[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minA[i]=min(minA[i+1],nums[i]);
        }

        int ans;
        for(int i=0;i<n-1;i++)
        {
            if(maxA[i]<=minA[i+1])
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.

II Approach (Optimal Method)

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int maxE=nums[0];
        int maxP=nums[0];
        int ans=1;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<maxE)
            {
                ans=i+1;
                maxE=maxP;
            }
            else
                maxP=max(maxP,nums[i]);
        }
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.