I-Approach 

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        int count=0;
        
        unordered_set<char> letter;
        for(int i=0;i<n;i++)
        {
            letter.insert(s[i]);
        }

        for(auto ch:letter)
        {
            int first_index=-1;
            int last_index=-1;

            for(int i=0;i<n;i++)
            {
                if(s[i]==ch)
                {
                    if(first_index==-1)
                    {
                        first_index=i;
                    }

                    last_index=i;
                }
            }
            unordered_set<char> st;

            for(int i=first_index+1;i<last_index;i++)
            {
                st.insert(s[i]);
            }

            count+=st.size();
        }

        return count;
    }
};

Time Complexity = O(n);
Space Complexity = O(1);

Where, 'n' is the length of the given string s.
