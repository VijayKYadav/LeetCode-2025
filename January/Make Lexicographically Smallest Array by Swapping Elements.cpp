I Approach

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        map<int,queue<int>> mpG;
        unordered_map<int,int> mpK;

        int count=0;
        mpG[count].push(temp[0]);
        mpK[temp[0]]=count;

        for(int i=1;i<n;i++)
        {
            if((temp[i]-temp[i-1])<=limit)
            {
                mpG[count].push(temp[i]);
                mpK[temp[i]]=count;
            }
            else
            {
                count++;
                mpG[count].push(temp[i]);
                mpK[temp[i]]=count;
            }
        }

        for(int i=0;i<n;i++)
        {
            int key=mpK[nums[i]];
            int val=mpG[key].front();

            mpG[key].pop();
            nums[i]=val;
        }
        return nums;
    }
};

Time Complexity: O(n*log(n)
Space Complexity: O(n)
 
where, 'n' is the size of the given array 'nums'.