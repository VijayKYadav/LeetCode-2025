I Approach (Brute-Force Method)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int count=0;

        for(int i=0;i<n;i++)
        {
            string temp=logs[i];

            if(temp=="../")
            {
                if(count>0)
                    count--;
            }
            else if(temp!="./")
                count++;
        }
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'logs'.