I Approach

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int count=1;    
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1' && s[i-1]=='0')
                count++;
        }
        
        if(count==1)
            return true;
        return false;
    }
};


Time Complexity: O(n)
Space Complexity: O(1) 
where, 'n' is the length of the given string 's'.