I Approach (Using Binary Search)

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        int minE=*min_element(ranks.begin(),ranks.end());

        long long maxT=(long long)cars*cars*minE;
        long long minT=1;
        
        while(minT<maxT)
        {
            long long midT=minT+(maxT-minT)/2;

            if(check(ranks,cars,midT))
                maxT=midT;
            else
                minT=midT+1;
        }

        return maxT;
    }

    bool check(vector<int> &ranks, int cars, double time)
    {
        int n=ranks.size();

        for(int i=0;i<n;i++)
        {
            cars-=(int)sqrt(time/ranks[i]);
            if(cars<=0)
                return true;
        }

        return false;
    }
};

Time Complexity=O(n*m*k).
Space Complexity=O(1).

Where, 'n' is the size of in a given vector/array 'ranks' and
'm' is the number of 'cars' and 'k' is the maximum value of given vector/array 'ranks'.