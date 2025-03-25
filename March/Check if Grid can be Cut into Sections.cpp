I Approach (Using Sorting) (Optimal Method)

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m=rectangles.size();

        vector<pair<int,int>> h;
        vector<pair<int,int>> v;

        for(int i=0;i<m;i++)
        {
            h.push_back({rectangles[i][0],rectangles[i][2]});
            v.push_back({rectangles[i][1],rectangles[i][3]});
        }

        int count=0;
        sort(h.begin(),h.end());
        int start=-1;
        int end=-1;

        for(int i=0;i<m;i++)
        {
            if(end<=h[i].first)
            {
                count++;
                start=h[i].first;
                end=h[i].second;
            }
            else 
                end=max(end,h[i].second);
            
            if(count==3)
                return true;
        }
        start=-1;
        end=-1;
        count=0;
        sort(v.begin(),v.end());

        for(int i=0;i<m;i++)
        {
            if(end<=v[i].first)
            {
                count++;
                start=v[i].first;
                end=v[i].second;
            }
            else 
                end=max(end,v[i].second);
            
            if(count==3)
                return true;
        }

        return false;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where,'n' is the size of the given 2D-Vector 'rectangles'.