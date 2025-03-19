I Approach (Using Sliding Window) (Optimal Method)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        while(i<n-2)
        {
            if(nums[i]==0)
            {
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];

                count++;
            }
            i++;
        }

        if(nums[i]==0 || nums[i+1]==0)
            return -1;
        
        return count;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n*n).

Where, 'n' is the size of in a given vector/array 'arr'.

This, solution will give TLE(Time Limit Exceeded).

II Approach (Using Unoreded_Set+Bitwies Operation)(Optimal Method)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();

        unordered_set<int> st;

        for( int i=0;i<n;i++) 
        {
            st.insert(arr[i]);
            for( int j=i-1;j>=0;j--)
            {
                if((arr[i]|arr[j])==arr[j])
                    break;
                arr[j] |= arr[i];
                st.insert(arr[j]);
            }
        }
        return st.size();
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of a given vector/array 'nums'.

