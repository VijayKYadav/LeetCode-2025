I Approach (Using Bit Manipulation)

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count2=0;
        int n1=num1;
        int n2=num2;
        
        while(n2)
        {
            count2+=n2&1;
            n2=n2>>1;
        }

        int len1=0;
        int count1=0;

        while(n1)
        {
            len1++;
            count1+=n1&1;
            n1=n1>>1;
        }
        int ans=0;
        if(count2==count1)
            return num1;
        else if(count1>count2)
        {
            int d=count1-count2;
            n1=num1;
            int n=num1;
            int p=1;
            while(d)
            {
                int bit=n1&1;
                if(bit)
                {
                    d--;
                    n=n^p;
                }
                p=p<<1;
                n1=n1>>1;
            }
            ans=n;
        }
        else 
        {
            int d=count2-count1;
            int n1=num1;
            int n=num1;
            int p=1;

            while(d)
            {
                int bit=n1&1;

                if(bit==0)
                {
                    d--;
                    n=n^p;
                }
                p=p<<1;
                n1=n1>>1;
            }

            while(d)
            {
                n=n*2+1;
                d--;
            }

            ans=n;
        }

        return ans;
    }
};

Time Complexity: O(log(num1)+log(num2))
Space Complexity: O(1) 
where, 'num1' and 'num2' are the given integers.
