I Approach (Using Ordered_Map of 'Key' of Integer Data-type and 'Value' of Integer Data-type)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            mp[nums1[i][0]]=nums1[i][1];
        }

        for(int i=0;i<m;i++)
        {
            mp[nums2[i][0]]+=nums2[i][1];
        }
        vector<vector<int>> ans;
        for(auto it:mp)
        {
            ans.push_back({it.first,it.second});
        }

        return ans;
    }
};

Time Complexity=O(n+m)log(n+m).
Space Complexity=O(n+m).

Where, 'n' is the size of the given 2D-vector 'nums1' and
'm' is the size of the given 2D-vector 'nums2'.

II Approach (Using Two Pointer) (Since the given two 2D-vector num1 and num2 are sorted on the bases of ID)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>> ans;
        int firstP=0;
        int secondP=0;
        
        while(firstP<n && secondP<m)
        {
            if(nums1[firstP][0]<nums2[secondP][0])
            {
                ans.push_back({nums1[firstP][0],nums1[firstP][1]});
                firstP++;
            }
            else if(nums1[firstP][0]>nums2[secondP][0])
            {
                ans.push_back({nums2[secondP][0],nums2[secondP][1]});
                secondP++;
            }
            else
            {
                ans.push_back({nums1[firstP][0],nums1[firstP][1]+nums2[secondP][1]});
                firstP++;
                secondP++;
            }
        }

        while(firstP<n)
        {
            ans.push_back({nums1[firstP][0],nums1[firstP][1]});
            firstP++;
        }

        while(secondP<m)
        {
            ans.push_back({nums2[secondP][0],nums2[secondP][1]});
            secondP++;
        }

        return ans;
    }
};

Time Complexity=O(n+m).
Space Complexity=O(n+m).

Where, 'n' is the size of the given 2D-vector 'nums1' and
'm' is the size of the given 2D-vector 'nums2'.