I Approach (Optimal Method)

class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();

        int possibleCount=0;

        for(int i=1;i<n;i++)
        {
            if(word[i-1]==word[i])
                possibleCount++;
        }
        
        return possibleCount+1;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where,'n' is the size of given vector/array 'nums'.