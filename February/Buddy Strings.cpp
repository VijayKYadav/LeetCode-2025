I Approach (Using HashMap)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1=s.length();
        int n2=goal.length();

        if(n1!=n2)
            return false;
        
        int count=0;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        for(int i=0;i<n1;i++)
        {
            if(s[i]!=goal[i])
                count++;

            if(count>2)
                return false;
            
            mp1[s[i]-'a']++;
            mp2[goal[i]-'a']++;
        }
        
        int checkEven=0;

        for(int i=0;i<26;i++)
        {
            if(mp1[i]!=mp2[i])
                return false;
            
            if(mp1[i]>1)
                checkEven++; 
        }

        if(count==2)
            return true;
        
        if(checkEven>0)
            return true;
        
        return false;
    }
};

Time Complexity=O(n)
Space Complexity=O(26)=>O(1)

Where, 'n' is the length of the given string 's' or 'goal'.

