I Approach (Using Unordered_Set + Policy Based Data Structure in gcc++)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();

        ordered_set st1,st2;
        st1.insert(nums[0]);
        st2.insert(nums[1]);

        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2;i<n;i++)
        {
            int count1=st1.order_of_key(nums[i]);
            int count2=st2.order_of_key(nums[i]);

            if(count1>count2)
            {
                arr1.push_back(nums[i]);
                st1.insert(nums[i]);
            }
            else if(count1<count2)
            {
                arr2.push_back(nums[i]);
                st2.insert(nums[i]);
            }
            else if(arr1.size()<=arr2.size())
            {
                arr1.push_back(nums[i]);
                st1.insert(nums[i]);
            }
            else if(arr1.size()>arr2.size())
            {
                arr2.push_back(nums[i]);
                st2.insert(nums[i]);
            }
        }

        for(int ele :arr2)
           arr1.push_back(ele);
        
        return arr1;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where, 'n' is the size of in a given vector/array 'nums'.