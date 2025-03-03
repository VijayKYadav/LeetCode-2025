I Approach (Brute-Force Method)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        
        while(columnNumber>0)
        {
            columnNumber--;

            char c=columnNumber%26+'A';
            ans=c+ans;
            columnNumber=columnNumber/26;
        }

        return ans;
    }
};

Time Complexity=O(log(n)).
Space Complexity=O(1).

Where, 'n' is the given Integer 'columnNumber'.