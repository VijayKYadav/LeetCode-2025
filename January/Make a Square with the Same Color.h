I-Approach 

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {

        int wC;
        int bC;  

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                wC=0;
                bC=0;

                if(grid[i][j]=='W')
                    wC++;
                else
                    bC++;
                
                if(grid[i][j+1]=='W')
                    wC++;
                else
                    bC++;
                
                if(grid[i+1][j]=='W')
                    wC++;
                else
                    bC++;

                if(grid[i+1][j+1]=='W')
                    wC++;
                else
                    bC++;

                if(wC!=bC)
                    return true;
            }

        }

        return false;
    }
};

Time Complexity = O(n);
Space Complexity = O(n);

Where, 'n' is the size of the given array arr.

II Approach (Without Using Space and Two Pass)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size()-1;
        int zC=0;

        for(int i=0;i<=n-zC;i++)
        {
            if(arr[i]==0)
            {
                if(i==n-zC)
                {
                    arr[n]=0;
                    n--;
                    break;
                }
                zC++;
            }
        }
        int last=n-zC;
        for(int i=last;i>=0;i--)
        {
            arr[n--]=arr[i];
            if(arr[i]==0)
            {
                arr[n--]=0;
            }
        }
    }
};

Time Complexity = O(1);
Space Complexity = O(1);
