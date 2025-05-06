I Approach (Optimal Method) (Using Unordered_Map)

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[i]=nums[i];
        
        vector<int> ans(n);

        for(int i=0;i<n;i++)
            ans[i]=nums[mp[i]];

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of the given vector/arrray 'nums'.


II Approach (Using Binary Search) (Optimal Method)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long count=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            int u=lowerBS(nums,i+1,n-1,upper-nums[i]+1);
            int l=lowerBS(nums,i+1,n-1,lower-nums[i]);
            count+=u-l;
        }

        return count;
    }

    int lowerBS(vector<int> &nums, int start, int end, int L)
    { 
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(nums[mid]>=L)
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(1).

Where,'n' is the size of the given vector/arrray 'nums'.

III Approach (Using Two-Pointer) (Optimal Method)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        return lowerBound(nums,upper+1)-lowerBound(nums,lower);
    }

    long long lowerBound(vector<int> &nums, int value)
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        long long ans=0;

        while(start<end)
        {
            int sum=nums[start]+nums[end];

            if(sum<value)
            {
                ans+=(end-start);
                start++;
            }
            else
                end--;
        }

        return ans;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(1).

Where,'n' is the size of the given vector/arrray 'nums'.
