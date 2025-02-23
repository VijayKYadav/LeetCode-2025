I Approach (Using Brute-Force Method)

class Solution {
public:
    bool hasSameDigits(string s) {
        string temp=s;
        while(temp.length()>2)
        {
            string t="";
            int len=temp.length();

            for(int i=1;i<len;i++)
            {
                int f=temp[i-1]-'0';
                int s=temp[i]-'0';
                int r=(f+s)%10;

                t+=(r+'0');
            }
            temp=t;
        }

        return temp[0]==temp[1];
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the length of the given string 's';