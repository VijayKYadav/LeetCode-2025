I Approach

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        bool flag=true;
        int count=0;
        while(flag)
        {
            flag=false;
            for(int i=1;i<n;i++)
            {
                if(s[i]=='1' && s[i-1]=='0')
                {
                    swap(s[i],s[i-1]);
                    i++;
                    flag=true;
                }
            }

            if(flag)
                count++;
        }
        return count;
    }
};

Time Complexity: O(n*n)
Space Complexity: O(1) 
where, 'n' is the length of the given string 's'.