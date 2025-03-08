I Approach (Using Sliding-Window) (Optimal Method)

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();

        int operationC=INT_MAX;
        int countW=0;
        int j=0;
        int i=0;

        while(j<n)
        {
            
            if(blocks[j]=='W')
                countW++;
            
            if(j-i+1==k)
            {
                operationC=min(operationC,countW);
                if(blocks[i]=='W')
                    countW--;
                i++;
            }
            j++;
        }
        
        return operationC;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 'blocks'.