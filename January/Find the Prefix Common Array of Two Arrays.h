I Approach

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;

        unordered_set<int> sA;
        unordered_set<int> sB;

        for(int i=0;i<n;i++)
        {
            int count=0;
            sA.insert(A[i]);
            sB.insert(B[i]);

            for(int j=0;j<=i;j++)
            {
                if(sB.find(A[j])!=sB.end())
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};

Time Complexity: O(n*n)
Space Complexity: O(n) 
where, 'n' is the size of the given vector 'A' and 'B'.

II Approach (Using two unordered set)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;

        unordered_set<int> sA;
        unordered_set<int> sB;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==B[i])
                count++;
            else
            {
                if(sB.find(A[i])!=sB.end())
                    count++;
                else
                    sA.insert(A[i]);

                if(sA.find(B[i])!=sA.end())
                    count++;
                else
                    sB.insert(B[i]);
            }

            ans.push_back(count);
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
where, 'n' is the size of the given vector 'A' and 'B'.

III Approach (Using Hash map) (Most Optimal Approach)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;

        vector<int> mp(n+1,0);

        int count=0;
        for(int i=0;i<n;i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;

            if(A[i]==B[i])
                count++;
            else
            {
                if(mp[A[i]]==2)
                    count++;
                
                if(mp[B[i]]==2)
                    count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
where, 'n' is the size of the given vector 'A' and 'B'.

