I Approach (Using Stack)

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();

        stack<int> st;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            string temp=operations[i];

            if(temp=="C")
            {
                int t=st.top();
                st.pop();
                sum-=t;
            }
            else if(temp=="D")
            {
                int t=st.top();
                st.push(2*t);
                sum+=2*t;
            }
            else if(temp=="+")
            {
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();

                st.push(second);
                st.push(first);
                st.push(first+second);
                sum+=first+second;
            }
            else 
            {
                int score=stoi(temp);
                st.push(score);
                sum+=score;
            }
        }

        return sum;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'operations'.