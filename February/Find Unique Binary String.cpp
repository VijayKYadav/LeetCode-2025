I Approach

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string st;
        for(int i=0;i<n;i++)
        {

            if(nums[i][i]=='0')
            {
                st+='1';
            }
            else
            {
                st+='0';
            }
        }
        return st;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.