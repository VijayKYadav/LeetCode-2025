I-Approach

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int n=items1.size();
        int m=items2.size();

        map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[items1[i][0]]+=items1[i][1];
        }

        for(int i=0;i<m;i++)
        {
            mp[items2[i][0]]+=items2[i][1];
        }

        vector<vector<int>> ans;

        for(pair<int,int> p:mp)
        {
            vector<int> items(2);
            items[0]=p.first;
            items[1]=p.second;

            ans.push_back(items);
        }

        return ans;
    }
};

Time Complexity = O(n*log(n)+m*log(m));
Space Complexity = O(n+m);

Where, 'n' is the size of the given array items1 and 'm' is the size of the given array items2.