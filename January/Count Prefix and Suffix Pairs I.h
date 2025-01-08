I-Approach

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(solve(words[i],words[j]))
                    count++;
            }
        }
        
        return count;
    }
    
    bool solve(string a, string b)
    {
        int n1=a.length();
        int n2=b.length();
        
        if(n1>n2)
            return false;
        
        for(int i=0;i<n1;i++)
        {
            if(a[i]!=b[i])
                return false;
            if(a[i]!=b[n2-n1+i])
                return false;
        }
        
        return true;
    }
};

Time Complexity = O(n*n*m);
Space Complexity = O(1);
Where, n is the size of the given string array words and 
'm' is the length of the longest string in given array words.
