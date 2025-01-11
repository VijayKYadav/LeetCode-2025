I Approach

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();

        vector<bool> vi(n,false);
        int count=0;

        for(int i=0;i<n-1;i++)
        {
            if(vi[i]==false)
            {
                vi[i]=true;

                for(int j=i+1;j<n;j++)
                {
                    if(check(words[i],words[j]))
                    {
                        count++;
                        vi[j]=true;
                    }
                }
            }
        }

        return count;
    }

    bool check(string &s1, string &s2)
    {
        if(s1[0]==s2[1] && s1[1]==s2[0])
            return true;
        return false;
    }
};


Time Complexity: O(n*n)
Space Complexity: O(n) 
where, 'n' is the size of the given string array 'words'.

II Approach

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>mp;
        int res=0;
        for(auto it:words){
            string s=it;
            reverse(it.begin(),it.end());
            if(mp.find(it)==mp.end()){
                mp.insert(s);
            }
            else res++;
           
        }
        return res;
    }
};

Time Complexity: O(n)
Space Complexity: O(n) 
where, 'n' is the size of the given string array 'words'.