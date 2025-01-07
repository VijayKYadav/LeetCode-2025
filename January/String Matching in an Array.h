I-Approach

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(words[j].contains(words[i]))
                    {
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }

    bool solve(string &s1, string &s2)
    {
        int n1=s1.length();
        int n2=s2.length();

        if(n1<n2)
            return false;
        
        int i=0;
        int j=0;

        while(i<n1 && j<n2)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j=0;
                if(s1[i]==s2[j])
                {
                    i++;
                    j++;
                }
                else
                    i++;
            }
        }

        if(j==n2)
            return true;
        return false;
    }
};

Time Complexity = O(n^2*m^2);
Space Complexity = O(n*m);
Where, n is the size of the given string array words and 
'm' is the length of the longest string in given array words.
