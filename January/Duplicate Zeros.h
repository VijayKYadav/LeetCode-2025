I-Approach (Using Space(i.e queue) and Two Pass)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        queue<int> q;

        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }

        for(int i=0;i<n;i++)
        {
            arr[i]=q.front();
            if(i+1<n && q.front()==0)
            {
                arr[i+1]=0;
                i++;
            }
            q.pop();
        }
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

Time Complexity = O(n);
Space Complexity = O(1);

Where, 'n' is the size of the given array arr.