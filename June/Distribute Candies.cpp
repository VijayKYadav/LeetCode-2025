I Approach (Optimal Method) (Using Unodered_Set)

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();

        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(candyType[i]);
        }
        int diffT=st.size();
        return min(diffT,n/2);
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of given vector/array 'candyType'.