I Approach (Brute-Force Method)

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char cL=s[0];
        char cH=s[3];
        char rL=s[1];
        char rH=s[4];

        vector<string> ans;

        for(char c=cL;c<=cH;c++)
        {
            for(char r=rL;r<=rH;r++)
            {
                string t="";
                t+=c;
                t+=r;
                ans.push_back(t);
            }
        }

        return ans;
    }
};

Time Complexity=O(n*m).
Space Complexity=O(1).

Where, 'n' is the number of the row in a given 'excel sheet' and 
'm' is the number of column in a given 'excel sheet'.