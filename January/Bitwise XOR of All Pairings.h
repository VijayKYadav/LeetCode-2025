I Approach (Using Bit Manipulation)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;

        if(n%2==0 && m%2==0)
            return 0;
        else if(n%2==0)
        {
            for(int i=0;i<n;i++)
            {
                ans=ans^nums1[i];
            } 
        }
        else if(m%2==0)
        {
            for(int i=0;i<m;i++)
            {
                ans=ans^nums2[i];
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans=ans^nums1[i];
            }

            for(int i=0;i<m;i++)
            {
                ans=ans^nums2[i];
            }
        }

        return ans;
    }
};

Time Complexity: O(n+m)
Space Complexity: O(1) 
where, 'n' and 'm' are the size of the given 
array 'nums1' and 'nums2' respectively.

II Approach (Using Bit Manipulation More Optimal/Efficient)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int xor1=0;
        int xor2=0;

        if(n%2)
        {
            for(int i=0;i<m;i++)
            {
                xor1=xor1^nums2[i];
            } 
        }

        if(m%2)
        {
            for(int i=0;i<n;i++)
            {
                xor2=xor2^nums1[i];
            }
        }

        return xor1^xor2;
    }
};

Time Complexity: O(n+m)
Space Complexity: O(1) 
where, 'n' and 'm' are the size of the given 
array 'nums1' and 'nums2' respectively.
