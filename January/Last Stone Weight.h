I Approach 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();

        priority_queue<int> pq; // Max_Heap

        for(int ele:stones)
        {
            pq.push(ele);
        }

        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();

            if(second<first)
            {
                int diff=first-second;
                pq.push(diff);
            }
        }

        if(pq.empty())
            return 0;
        return pq.top();
    }
};

Time Complexity: O(n*log(n))
Space Complexity: O(n) 
where, 'n' is the size of the given array 'stones'.