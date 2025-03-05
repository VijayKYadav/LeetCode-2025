I Approach (Brute-Force Method)

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1)
            return 0;
        
        if(n%2)
            return n;
        
        return n/2;
    }
};

Time Complexity=O(1).
Space Complexity=O(1).

Where, 'n' is the given Integer.