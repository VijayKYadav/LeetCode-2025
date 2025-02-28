I Approach (Using Binary Search) (Optimal Method)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int is=0;
        int ih=m-1;
        int i=0;
        while(is<=ih)
        {
            int mid=is+(ih-is)/2;
            if(matrix[mid][0]==target)
                return true;
            else
            {
                if(matrix[mid][0]>target)
                {
                    ih=mid-1;
                }
                else
                {
                    i=max(i,mid);
                    is=mid+1;
                }
            }
        }
        
        int js=0;
        int jh=n-1;
        while(js<=jh)
        {
            int mid=js+(jh-js)/2;
            if(matrix[i][mid]==target)
                return true;
            else
            {
                if(matrix[i][mid]>target)
                {
                    jh=mid-1;
                }
                else
                {
                    js=mid+1;
                }
            }
        }
        return false;

    }
};

Time Complexity=O(log(n)+log(m)).
Space Complexity=O(1).

Where, 'n' is the number of the column's in a given 2D-array 'matrix' and
'm' is the number of the row's in a given 2D-array 'matrix'.

II Approach (Using Binary Search)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int start=0;
        int end=n*m-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            int row=mid/m;
            int col=mid%m;

            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
};

Time Complexity=O(log(n*m)).
Space Complexity=O(1).

Where, 'n' is the number of the column's in a given 2D-array 'matrix' and
'm' is the number of the row's in a given 2D-array 'matrix'.