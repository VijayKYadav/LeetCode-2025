I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);

        int ind=0;
        int c=1;

        while(c<=candies)
        {
            ans[ind%num_people]+=c;
            ind++;
            candies=candies-c;
            c++;
        }

        if(candies>0)
            ans[ind%num_people]+=candies;

        return ans;
    }
};

Time Complexity=O(log(candies)).
Space Complexity=O(1).

Where, 'candies' is the given Integer.