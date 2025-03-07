I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        int last=-1;

        for(int i=left;i<=right;i++)
        {
            if(checkIsPrime(i))
            {
                if(ans[0]==-1)
                {
                    ans[0]=ans[1];
                    ans[1]=i;
                }
                else
                {
                    if(last==-1)
                    {
                        if((ans[1]-ans[0])>i-ans[1])
                        {
                            ans[0]=ans[1];
                            ans[1]=i;
                        }
                        else
                            last=i;
                    }
                    else
                    {
                        if((i-last)<(ans[1]-ans[0]))
                        {
                            ans[0]=last;
                            ans[1]=i;
                        }
                        last=i;
                    }
                }
            }
        }

        if(ans[0]==-1)
            return {-1,-1};
        
        return ans;
        
    }

    bool checkIsPrime(int n)
    {
        if(n==1)
            return false;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }

        return true;
    }
};

Time Complexity=O((right-left+1)*log(right)).
Space Complexity=O(1).

Where, 'left' and 'right' is the given Integer.