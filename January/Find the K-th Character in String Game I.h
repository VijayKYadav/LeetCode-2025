I-Approach 

class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k)
        {
            int n=s.length();
            string st="";
            for(int i=0;i<n;i++)
            {
                st+=(s[i]+1);
            }
            s+=st;
        }
        return s[k-1];
    }
};

Time Complexity = O(log(k));
Space Complexity = O(k);

