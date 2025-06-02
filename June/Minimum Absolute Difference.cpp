I Approach (Optimal Method) (Using Sorting)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int minAD=INT_MAX;

        for(int i=0;i<n-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                if(arr[i+1]-arr[i]<minAD)
                    minAD=arr[i+1]-arr[i];
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]==minAD)
            {
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(1).

Where,'n' is the size of given vector/array 'arr'.