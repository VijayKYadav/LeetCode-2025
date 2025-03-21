I Approach (Using Brute-Force)

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int nR=recipes.size();
        int nS=supplies.size();

        vector<string> ans;
        vector<bool> status(nR,false);

        unordered_set<string> stS;
        for(int i=0;i<nS;i++)
        {
            stS.insert(supplies[i]);
        }
        int count;

        do
        {
            count=ans.size();

            for(int i=0;i<nR;i++)
            {
                if(status[i]==false)
                {
                    if(check(ingredients[i],stS))
                    {
                        ans.push_back(recipes[i]);
                        stS.insert(recipes[i]);
                        status[i]=true;
                    }
                }
            }
        }
        while(count!=ans.size());

        return ans;
    }

    bool check(vector<string> indG, unordered_set<string> &stS)
    {
        int len=indG.size();

        for(int i=0;i<len;i++)
        {
            if(stS.find(indG[i])==stS.end())
                return false;
        }

        return true;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n+m).

Where,'n' is the size of a given vector/array 'recipes' and
'm' is the size of a given vector/array 'supplies'.

