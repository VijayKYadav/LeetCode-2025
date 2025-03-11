I Approach (Using Brute-Force Method)

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.length();
        int count=0;

        for(int i=0;i<n;i++)
        {
            string t="";
            for(int j=i;j<n;j++)
            {
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
                {
                    t+=word[j];
                    if(t.length()>=5 && solve(t))
                        count++;
                }
                else
                    break;
            }
        }

        return count;
    }

    bool solve(string temp)
    {
        int n=temp.length();

        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[temp[i]]++;
        }

        if(mp.size()==5)
            return true;
        
        return false;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where, 'n' is the length of the given string 'word'.
    

II Approach (Using Sliding-Window + Unordered_Map) (Optimal Method)

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.length();
        int count=0;
        
        int i=0;
        int j=0;
        unordered_map<char,int> mp;

        while(j<n)
        {
            if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
                mp[word[j]]++;
            else
            {
                i=j+1;
                mp.clear();
            }
            
            if(mp.size()==5)
            {
                int t=j;

                while(word[t]=='a' || word[t]=='e' || word[t]=='i' || word[t]=='o' || word[t]=='u')
                    t++;

                while(mp.size()==5)
                {
                    count+=t-j;
                    mp[word[i]]--;
                    
                    if(mp[word[i]]==0)
                        mp.erase(word[i]);

                    i++;
                }
            }

            j++;
        }
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 'word'.
