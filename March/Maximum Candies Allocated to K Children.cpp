I Approach (Using Binary-Search) (Optimal Method)

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();

        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+candies[i];
        }

        if(sum<k)
            return 0;        
    
        int start=1;
        int end=sum/k;

        while(start<=end)
        {
            int mid=(end-start)/2+start;

            if(check(candies,mid,k))
                start=mid+1;
            else
                end=mid-1;
        }
        
        return end;
    }

    bool check(vector<int> &candies, int mid, int k)
    {
        long long count=0;
        int n=candies.size();

        for(int i=0;i<n;i++)
        {
            count+=candies[i]/mid;
            if(count>=k)
                return true;
        }
        return false;
    }
};

Time Complexity=O(n*log(sum/k)).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'candies',
'sum' is the sum of all the element in a given vector/array 'candies' 
and 'k' is the given Integer 'queries'.