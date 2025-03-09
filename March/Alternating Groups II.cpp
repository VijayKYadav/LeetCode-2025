I Approach (Using Sliding-Window + Circular Array) (Optimal Method)

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        
        int i=0;
        int j=1;
        int count=0;

        while(i<n)
        {
            if(colors[j]==colors[(n+j-1)%n])
            {
                if(j<i)
                    break;
                i=j;
            }
            int d;

            if(j>=i)
                d=j-i+1;
            else
                d=n-i+j+1;
			
            if(d==k)
            {
                count++;
                i++;
            }
            
            j++;
            j=j%n;
        }

        return count;
    }
};

Time Complexity=O(n+k).
Space Complexity=O(1).

Where, 'n' is the size of the given array 'colors' and 
'k' is the contiguous tiles in the circle with alternating colors 
(each tile in the group except the first and last 
one has a different color from its left and right tiles).