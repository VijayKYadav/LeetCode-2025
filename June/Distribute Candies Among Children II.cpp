I Approach (Optimal Method) (Using Inclusion and Exclusion Principle)

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return fact(n+2)-3*fact(n-limit+1)+3*fact(n-2*limit)-fact(n-3*limit-1);
    }
    long long fact(int x)
    {
        if(x<0)
            return 0;
        
        return (long long)x*(x-1)/2;
    }
};

Time Complexity=O(1).
Space Complexity=O(1).

Where,'n' is the number of the given 'Candies'.