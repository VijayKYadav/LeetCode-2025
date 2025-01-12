I Approach

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if (n%2)
            return false;

        stack<int> s1, s2;

        for (int i=0; i<n; i++) {
            if (locked[i]=='0') 
                s2.push(i);
            else
            { 
                if (s[i] == '(')
                    s1.push(i);
                else 
                {
                    if (!s1.empty())
                        s1.pop();
                    else if (!s2.empty())
                        s2.pop();
                    else 
                        return false;
                }
            }
        }

        while (!s1.empty() && !s2.empty() && s1.top() < s2.top()) 
        {
            s1.pop();
            s2.pop();
        }

        if (!s1.empty())
            return false;

        return true;

    }
};

Time Complexity: O(n)
Space Complexity: O(n) 
where, 'n' is the length of the given string 's'.

II Approach

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2==1)
            return false;

        int openC=0;
        int zeroC=0;

        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                zeroC++;
            }
            else
            {
                if(s[i]=='(')
                    openC++;
                else
                {
                    if(openC>0)
                        openC--;
                    else
                    {
                        if(zeroC>0)
                            zeroC--;
                        else
                            return false;
                    }
                }
            }
        }

        int balance=0;
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                balance--;
                zeroC--;
            }
            else
            {
                if(s[i]=='(')
                {
                    balance++;
                    openC--;
                }
                else
                {
                    balance--;
                }
            }

            if(balance>0)
                return false;
                
            if(zeroC==0 && openC==0)
                return true;
        }

        if(openC>0)
            return false;
        
        return true;

    }
};

Time Complexity: O(n)
Space Complexity: O(1) 
where, 'n' is the length of the given string 's'.

