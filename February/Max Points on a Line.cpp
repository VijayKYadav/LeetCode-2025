I Approach (Using Brute force)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)
            return 1;

        int maxP=0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count=2;
                for(int k=0;k<n;k++)
                {
                    if(!(points[i][0]==points[k][0] && points[i][1]==points[k][1]) && !(points[j][0]==points[k][0] && points[j][1]==points[k][1]))
                    {
                        if(solve(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]))
                            count++;
                    }
                }

                maxP=max(maxP,count);
            }
        }
        return maxP;
    }

    bool solve(int x1, int y1, int x2, int y2, int x, int y)
    {
        int left=(y-y1)*(x2-x1);
        int right=(y2-y1)*(x-x1);

        if(left==right)
            return true;
        else
            return false;
    }
};

Time Complexity=O(n*n*n)
Space Complexity=O(1)

Where, 'n' is the size of the given 2D-array 'points'.

II Approach (Optimal Method)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)
            return 1;

        int maxP=0;

        for(int i=0;i<n-1;i++)
        {
            unordered_map<double,int> mp;
            for(int j=i+1;j<n;j++)
            {
                double dx=(double)(points[j][0]-points[i][0]);
                double dy=(double)(points[j][1]-points[i][1]);

                if(dx==0)
                {
                    mp[INT_MAX]++;
                }
                else 
                {
                    double m=dy/dx;
                    mp[m]++;
                }
            }

            int count=0;
            for(auto it:mp)
            {
                count=max(count,it.second+1);
            }
            maxP=max(maxP,count);
        }
        return maxP;
    }
};

Time Complexity=O(n*n)
Space Complexity=O(n)

Where, 'n' is the size of the given 2D-array 'points'.

