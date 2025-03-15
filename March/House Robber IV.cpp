I Approach (Using Binary-Search) (Optimal Method)

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();

        int minR=1;
        int maxR=*max_element(nums.begin(), nums.end());

        while(minR<maxR) 
        {
            int midR = (minR+maxR)/2;
            int possibleThefts = 0;

            for (int i=0;i<n;i++) 
            {
                if(nums[i]<=midR) 
                {
                    possibleThefts += 1;
                    i++;
                }
            }

            if (possibleThefts >= k)
                maxR=midR;
            else
                minR=midR+1;
        }

        return minR;
    }
};

Time Complexity=O(n*log(maxE)).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums' and
'maxE' is the maximum element in a given vector/array 'nums'.