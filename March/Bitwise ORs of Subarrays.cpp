I Approach (Using Brute-Force)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++)
        {
            int bitwiseOR=0;

            for(int j=i;j<n;j++)
            {
                bitwiseOR=bitwiseOR|arr[j];
                st.insert(bitwiseOR);
            }
        }

        return st.size();
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n*n).

Where, 'n' is the size of in a given vector/array 'arr'.

This, solution will give TLE(Time Limit Exceeded).

II Approach (Using Unoreded_Set+Bitwies Operation)(Optimal Method)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();

        unordered_set<int> st;

        for( int i=0;i<n;i++) 
        {
            st.insert(arr[i]);
            for( int j=i-1;j>=0;j--)
            {
                if((arr[i]|arr[j])==arr[j])
                    break;
                arr[j] |= arr[i];
                st.insert(arr[j]);
            }
        }
        return st.size();
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where, 'n' is the size of in a given vector/array 'arr'.

