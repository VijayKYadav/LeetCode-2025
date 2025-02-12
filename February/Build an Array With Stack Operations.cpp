I Approach (Using Concept of Stack without Stack Data Structure ) (Optimal Approach)

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int N=target.size();

        vector<string> ans;
        int popO=0;

        int ind=0;
        int streamI=1;

        while(ind<N)
        {
            if(target[ind]==streamI)
            {
                if(popO==0)
                {
                    ans.push_back("Push");
                }
                else
                {
                    while(popO!=0)
                    {
                        ans.push_back("Pop");
                        popO--;
                    }
                    ans.push_back("Push");
                }
                ind++;
            }
            else
            {
                ans.push_back("Push");
                popO++;
            }
            streamI++;
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the stream of the integers in the range [1, n].