I Approach (Using Concept of Stack without Stack Data Structure ) (Optimal Approach)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int el:nums)
        {
            pq.push(el);
        }
        
        int count=0;
        
        while(pq.top()<k)
        {
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            
            long long t=min(x,y)*2+max(x,y);
            pq.push(t);
            
            count++;
        }
        
        return count;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.