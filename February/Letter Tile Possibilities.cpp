I Approach (Using Recursion and Backing Tracking)

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n=tiles.length();

        vector<bool> used(n,false);
        unordered_set<string> ans;

        string curr="";
        solve(tiles,n,used,ans,curr);

        return ans.size()-1;
    }

    void solve(string &tiles, int n, vector<bool> &used, unordered_set<string> &ans, string &curr)
    {
        ans.insert(curr);

        for(int i=0;i<n;i++)
        {
            if(used[i]==false)
            {
                used[i]=true;
                curr.push_back(tiles[i]);

                solve(tiles,n,used,ans,curr);

                used[i]=false;
                curr.pop_back();
            }
        }
    }
};

Time Complexity=O(n!).
Space Complexity=O(n*n!)+O(n)~O(n*n!). // First is the size of ans and Second is for stack used for recursion. 

Where,  'n' is the length of the given string 'tiles'.


II Approach (Using Recursion and Backing Tracking and Frquency Count)

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n=tiles.length();

        vector<int> mp(26,0);
        
        for(int i=0;i<n;i++)
            mp[tiles[i]-'A']++;

        return solve(mp);
    }

    int solve(vector<int> &mp)
    {
        int count=0;

        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0)
            {
                count++;

                mp[i]--;
                count+=solve(mp);
                mp[i]++;
            }
        }

        return count;
    }
};

Time Complexity=O(2^n).
Space Complexity=O(n).

Where,  'n' is the length of the given string 'tiles'.
