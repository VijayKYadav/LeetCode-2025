I Approach (Using Binary Search)

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int positive=0;
        int negative=0;

        int start= 0;
        int end = n-1;

        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]>=0)
                end=mid-1;
            else
                start=mid+1;
        }
        negative = end+1;

        start = 0;
        end = n-1;
        while(start <= end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<=0)
                start=mid+1;
            else
                end=mid-1;
        }
        positive=n-start;

        int m=0;
        if(positive>=negative)
            m=positive;
        else
            m=negative;

        return m;
    }
};

Time Complexity=O(log(n)).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.

II Approach (Using Binary-Search) (Optimal Method)

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int positive=0;
        int negative=0;

        int start= 0;
        int end = n-1;

        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]>=0)
                end=mid-1;
            else
                start=mid+1;
        }
        negative=start;
    
        end = n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<=0)
                start=mid+1;
            else
                end=mid-1;
        }
        positive=n-start;

        if(positive>=negative)
            return positive;

        return negative;
    }
};

Time Complexity=O(log(n)).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.