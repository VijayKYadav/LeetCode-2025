I Approach (Using Euclidean Algorithm)

class Solution {
  public:
    int gcd(int a, int b) {
        int na=min(a,b);
        int nb=max(a,b);
        
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        
        return a;
    }
};

Time Complexity=O(log(min(a,b))).
Space Complexity=O(1).

Where, 'a' and 'b' are given two Integer's.