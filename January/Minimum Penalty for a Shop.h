I Approach (Using Prefix Sum Count of 'N' and Sufix Sum Count of 'Y' )

class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();

        int sCY=0;
        int pCN=0;

        for(int i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y')
                sCY++;
        }
        int p=INT_MAX;
        int ind;

        for(int i=0;i<n;i++)
        {
            if(p>(sCY+pCN))
            {
                p=sCY+pCN;
                ind=i;
            }

            if(customers[i]=='Y')
                sCY--;
            else
                pCN++;
        }
		
        if(p>(sCY+pCN))
            ind=n;


        return ind;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the length of the given string 'customers'.