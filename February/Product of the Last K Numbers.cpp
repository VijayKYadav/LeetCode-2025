I Approach

class ProductOfNumbers {
public:
    vector<int> ans;
    ProductOfNumbers() {
        ans.push_back(1);
    }
    
    void add(int num) {
        if(num==0)
        {
            ans.clear();
            ans.push_back(1);
        }
        else
            ans.push_back(ans.back()*num);
    }
    
    int getProduct(int k) {
        if(k>=ans.size())
            return 0;
        return ans.back()/ans[ans.size()-1-k];
    }
};

Time Complexity=O(1) for 'add' Operation and O(1) for 'getProduct' Operation.
Space Complexity=O(n).

Where,  'n' is the number of elements added to the 'ProductOfNumbers' object.