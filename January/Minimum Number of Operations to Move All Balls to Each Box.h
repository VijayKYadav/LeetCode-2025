I-Approach (Brute Force / Naive Method)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();

        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(boxes[j]=='1')
                    {
                        sum+=abs(j-i);
                    }
                }
            }
            ans[i]=sum;
        }

        return ans;
    }
};

Time Complexity = O(n*n);
Space Complexity = O(1);
Where, n is the length of the given binary string boxes.

II Approach (Using Two Pass)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();

        vector<int> left(n,0);
        vector<int> right(n,0);
        vector<int> ans(n,0);
        
        int oneC=0;
        int sum=0;

        for(int i=n-1;i>=0;i--)
        {
            sum=sum+oneC;
            right[i]=sum;
            if(boxes[i]=='1')
                oneC++;
        }
        oneC=0;
        sum=0;

        for(int i=0;i<n;i++)
        {
            sum=sum+oneC;
            left[i]=sum;
            if(boxes[i]=='1')
                oneC++;

            ans[i]=left[i]+right[i];
        }

        return ans;
    }
};

Time Complexity = O(n);
Space Complexity = O(n);
Where, n is the length of the given binary string boxes.

III Approach (Using One Pass)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();

        vector<int> ans(n,0);
        
        int oneCL=0,oneCR=0;
        int sumL=0,sumR=0;

        for(int i=0;i<n;i++)
        {
            ans[i]+=sumL;
            if(boxes[i]=='1')
                oneCL++;
            sumL+=oneCL;

            int j=n-1-i;
            ans[j]+=sumR;
            if(boxes[j]=='1')
                oneCR++;
            sumR+=oneCR;
        }

        return ans;
    }
};

Time Complexity = O(n);
Space Complexity = O(1);
Where, n is the length of the given binary string boxes.
