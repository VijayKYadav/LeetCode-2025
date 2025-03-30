I Approach (Using Unordered_map) (Brute-Force Method)

class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        unordered_set<char> st;
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(st.find(s[i])==st.end())
            {
                st.insert(s[i]);
            }
            else
            {
                count++;
                st.clear();
                st.insert(s[i]);
            }
        }

        return count+1;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where,'n' is the length of a given string 's'.

II Approach (Using HashMap) (Optimal Method)

class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        vector<int> mp(26,0);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(mp[s[i]-'a']==0)
            {
                mp[s[i]-'a']=1;
            }
            else
            {
                count++;
                for(int i=0;i<26;i++)
                {
                    mp[i]=0;
                }
                mp[s[i]-'a']=1;
            }
        }

        return count+1;
    }
};

Time Complexity=O(n).
Space Complexity=O(26)~O(1).

Where,'n' is the length of a given string 's'.