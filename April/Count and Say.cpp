I Approach (Brute-Force Method)

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        return say(countAndSay(n-1));
    }

    string say(string s)
    {
        int count=1;
        string st="";
        int n=s.length();
        char ch=s[0];

        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
                count++;
            else
            {
                string c=to_string(count);
                st+=c;
                st+=ch;
                ch=s[i];
                count=1;
            }
        }
        string c=to_string(count);
        st+=c;
        st+=ch;

        return st;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(1).

Where,'n' is the size of the given vector/arrray 'nums'.


II Approach (Using HashMap) (Optimal Method)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, vector<int>> indicesMap;
        for(int i = 0; i < n; i++) 
		{
            indicesMap[nums[i]].push_back(i);
        }

        unordered_set<int> div;
        for(int f=1;f*f<=k;f++) 
		{ 
            if(k%f==0) 
			{
                div.insert(f); 
                div.insert(k/f);
            }
        }

        for(auto& [num,indices]:indicesMap) 
		{
            unordered_map<int,int> factorsMap;

            for(int i:indices) 
			{
                int GCD=gcd(i, k);
                int j=k/GCD;

                result+=factorsMap[j];

                for(int f:div) 
				{
                    if(i%f==0) 
					{
                        factorsMap[f]++;
                    }
                }
            }
        }
        return result;
    }
};

Time Complexity=O(2^n).
Space Complexity=O(n).

Where,'n' is the given positive Integer.
