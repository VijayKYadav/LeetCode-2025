I Approach (Using Fast Exponentiation) (Optimal Method)

class Solution {
private:
    int mod=1e9+7;
public:
    int countGoodNumbers(long long n) {
        return solve(5, (n + 1) / 2) * solve(4, n / 2) % mod;
    }

    long long solve(long long x, long long y)
    {
        long long ans=1;

        while(y>0)
        {
            if(y%2)
            {
                ans=(ans*x)%mod;
                y--;
            }
            else
            {
                x=(x*x)%mod;
                y=y/2;
            }
        }
        return ans; 
    }
};

Time Complexity=O(log(n)).
Space Complexity=O(1).

Where,'n' is the given Integer's.
