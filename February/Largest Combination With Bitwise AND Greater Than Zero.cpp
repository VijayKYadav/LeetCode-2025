I Approach 

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        int maxE=*max_element(candidates.begin(),candidates.end());

        int size=0;
        int i=0;
        while(maxE>0)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(candidates[j] & (1<<i))
                    count++;

            }
            maxE=maxE>>1;
            i++;
            size=max(size,count);
        }

        return size;
    }
};

Time Complexity: O(n*b)
Space Complexity: O(1)
 
where, 'n' is the size of the given array 'candidates' and 
'b' is the number of bit's present in the binary representation of maximum element of a given array.