I Approach (Using Stack + Priority_Queue) (Optimal Method)

class Solution {
public:
    long long mod = 1e9+7;

    int distinctPrimeFactors(int N)
    {
        int ans = 0;
        if (N < 2) 
            return 0;

        if (N == 2) 
            return 1;
    
        unordered_map<int, bool> visited;
    
        for (int i = 2; i * i <= N; i++) 
        {
            while (N % i == 0) 
            {
                if (!visited[i]) 
                {
                    ans++;
                    visited[i] = 1;
                }
                N /= i;
            }
        }
        if (N > 2)
            ans++;

        return ans;
    }

    long long power(int x, int y)
    {
        if(x==1 || y==0)
            return 1;
        
        long long pow = power(x, y/2);
        pow%=mod;
        pow = (pow*pow)%mod;
        if(y%2 != 0)
            return (pow*x)%mod;
        return (pow)%mod;

    }

    int maximumScore(vector<int>& nums, int k) 
    {
        
        int n = nums.size();
    
        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++)
        {
            int dpf = distinctPrimeFactors(nums[i]);

            pq.push({nums[i], i});
            nums[i] = dpf;
        }

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if(st.empty())
                left[i] = i+1;
            else
            {
                left[i] = i - st.top();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            if(st.empty())
                right[i] = n-i;
            else
            {
                right[i] = st.top()-i;
            }

            st.push(i);
        }
        
        long long ans = 1;
        while(k > 0)
        {
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            long long subarrays = (long long)left[ind]*right[ind];
            if(subarrays > k)
            {
                ans *= (power(ele, k));
                ans%=mod;
            }
            else
            {
                ans *= power(ele, subarrays);
                ans%=mod;
            }
            int d=k-subarrays;
            k = max(d, 0);
        }

        return ans%mod;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.