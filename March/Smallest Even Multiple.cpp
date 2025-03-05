I Approach (Brute-Force Method)

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2)
            return 2*n;
        return n;
    }
};

Time Complexity=O(1).
Space Complexity=O(1).