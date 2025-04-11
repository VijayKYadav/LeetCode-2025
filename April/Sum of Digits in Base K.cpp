I Approach (Optimal Method)

class Solution {
public:
    int sumBase(int n, int k) {
        int sumD=0;

        while(n>0)
        {
            sumD+=n%k;
            n=n/k;
        }
        return sumD;
    }
};

Time Complexity=O(log(n)).
Space Complexity=O(1).

Where,'n' is the given Integer's.