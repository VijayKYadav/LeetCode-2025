I Approach (Brute-Force Method)

class Solution {
public:
    bool isThree(int n) {
        int count=0;

        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                count++;
        }

        return count==3;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the given Integer.