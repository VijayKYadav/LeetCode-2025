I Approach (Using Brute-Force Method)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length())
            s.erase(s.find(part),part.length());
        return s;
    }
};

Time Complexity=O(n*n/m).
Space Complexity=O(n).

Where, 'n' is the length of given string 's' and 
'm' is the length of the given string 'part'.