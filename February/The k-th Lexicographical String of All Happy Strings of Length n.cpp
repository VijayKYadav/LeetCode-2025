I Approach (Using Recursion and Backtracking ans Ordered_Set of Data Types String)

class Solution {
public:
    string getHappyString(int n, int k) {
        set<string> ans;
        string curr="";

        solve(n,ans,curr);

        if(ans.size()<k)
            return "";
        
        return *next(ans.begin(),(k-1));
    }

    void solve(int n, set<string> &ans, string &curr)
    {
        if(curr.length()==n)
        {
            ans.insert(curr);
            return ;
        }

        if(curr=="")
        {
            for(int i=0;i<3;i++)
            {
                curr.push_back(i+'a');
                solve(n,ans,curr);
                curr.pop_back();
            }
        }
        else
        {
            char ch=curr.back();
            for(int i=0;i<3;i++)
            {
                if(ch!=i+'a')
                {
                    curr.push_back(i+'a');
                    solve(n,ans,curr);
                    curr.pop_back();
                }
            }
        }
    }
};

Time Complexity=O(n*2^n).
Space Complexity=O(2^n).

Where, 'n' is the length of the HappyString.

II Approach	(Using Recursion and Backtracking) (Optimal Method)

class Solution {
public:
    string getHappyString(int n, int k) {
        string ans="";
        string curr="";
        int count=0;
        solve(n,k,count,ans,curr);
        return ans;
    }

    void solve(int n,int k,int &count,string &ans, string &curr)
    {
        if(curr.length()==n)
        {
            count++;
            if(count==k)
                ans=curr;
            return ;
        }

        if(curr=="")
        {
            for(int i=0;i<3;i++)
            {
                curr.push_back(i+'a');
                solve(n,k,count,ans,curr);
                curr.pop_back();
            }
        }
        else
        {
            char ch=curr.back();
            for(int i=0;i<3;i++)
            {
                if(ch!=i+'a')
                {
                    curr.push_back(i+'a');
                    solve(n,k,count,ans,curr);
                    curr.pop_back();
                }
            }
        }
    }
};

Time Complexity=O(n*k).
Space Complexity=O(n).

Where, 'n' is the length of the HappyString and 'k' is the given Integer.