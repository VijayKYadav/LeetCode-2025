I Approach

class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0)
            return (high-low)/2;
        return (high-low)/2+1;
    }
};

Time Complexity=O(1).
Space Complexity=O(1).