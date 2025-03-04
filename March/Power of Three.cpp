I Approach

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        
        
        while(n!=1)
        {
            if(n%3)
                return false;
            
            n=n/3;
        }
        return true;
    }
};

Time Complexity=O(log3(n))~O(log(n)).
Space Complexity=O(1).

Where, 'n' is the given Integer.