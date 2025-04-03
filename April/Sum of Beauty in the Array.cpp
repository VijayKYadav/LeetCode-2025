I Approach (Optimal Method)

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();

        vector<int> minA(n);
        vector<int> maxA(n);

        maxA[0]=nums[0];
        for(int i=1;i<n-1;i++)
        {
            maxA[i]=max(nums[i],maxA[i-1]);
        }

        minA[n-1]=nums[n-1];
        for(int i=n-2;i>0;i--)
        {
            minA[i]=min(nums[i],minA[i+1]);
        }

        bool two=true;
        bool one=true;
        int sumB=0;

        for(int i=1;i<n-1;i++)
        {
            if(maxA[i-1]<nums[i] && minA[i+1]>nums[i])
                sumB+=2;
            else if(nums[i-1]<nums[i] && nums[i+1]>nums[i])
                sumB+=1;
        }
        return sumB;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.