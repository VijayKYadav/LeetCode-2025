I Approach (Using Sliding-Window + Unordered_Map) (Optimal Method)

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return solve(word,k)-solve(word,k+1);
    }

    long long solve(string word, int k)
    {
        int n=word.length();

        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        long long count=0;
        int cC=0;

        while(j<n)
        {
            if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
                mp[word[j]]++;
            else
                cC++;
            
            while(mp.size()==5 && cC>=k)
            {
                count+=n-j;
                if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
                {
                    mp[word[i]]--;
                    if(mp[word[i]]==0)
                        mp.erase(word[i]);
                }
                else
                    cC--;

                i++;
            }

            j++;
        }
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 'word'.