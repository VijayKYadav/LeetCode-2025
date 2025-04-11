I Approach (Optimal Method)

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;

        for(int i=low;i<=high;i++)
        {
            if(checkE(i))
            {
                count++;
            }
        }
        return count;
    }

    bool checkE(int i)
    {
        int digitC=0;
        int n=i;
        while(n>0)
        {
            n=n/10;
            digitC++;
        }

        if(digitC%2)
            return false;
        
        int last=0;
        int first=0;
        n=i;
        for(int k=1;k<=digitC;k++)
        {
            if(k<=digitC/2)
            {
                last+=n%10;
                n=n/10;
            }
            else
            {
                first+=n%10;
                n=n/10;
            }
        }

        if(first==last)
            return true;
        else
            return false;
    }
};

Time Complexity=O(high-low).
Space Complexity=O(1).

Where,'low' and 'high' are the given Integer's.