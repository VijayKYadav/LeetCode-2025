I Approach

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();

        vector<int> ans(n);
        unordered_map<int,int> mp;
        unordered_set<int> col;
        unordered_map<int,int> colour;

        for(int i=0;i<n;i++)
        {
            if(mp.find(queries[i][0])==mp.end())
            {
                mp[queries[i][0]]=queries[i][1];
                colour[queries[i][1]]++;
                if(col.find(queries[i][1])==col.end())
                {
                    col.insert(queries[i][1]);
                }
            }
            else
            {
                if(mp[queries[i][0]]!=queries[i][1])
                {
                    colour[mp[queries[i][0]]]--;
                    if(colour[mp[queries[i][0]]]==0)
                        col.erase(mp[queries[i][0]]);

                    if(col.find(queries[i][1])==col.end())
                    {
                        col.insert(queries[i][1]);
                    }
                    colour[queries[i][1]]++;
                    mp[queries[i][0]]=queries[i][1];
                }
            }

            ans[i]=col.size();
        }

        return ans;
    }
};

Time Complexity=O(n)
Space Complexity=O(n)

Where, 'n' is the number row's in the given 2D-vector 'queries'.

