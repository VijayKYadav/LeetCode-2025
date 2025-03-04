I Approach (Using Ternary Representation)

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n)
        {
            if(n%3==2)
                return false;
            
            n=n/3;
        }
        return true;
    }
};

Time Complexity=O(log3(n))~O(log(n)).
Space Complexity=O(1).

Where, 'n' is the given Integer.