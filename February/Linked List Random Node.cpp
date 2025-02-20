I Approach

class Solution {
private:
    vector<int> t;
    int len;
public:
    Solution(ListNode* head) {
        ListNode* temp=head;

        while(temp)
        {
            t.push_back(temp->val);
            temp=temp->next;
        }
        len=t.size();
    }
    
    int getRandom() {
        return t[rand()%len];
    }
};

Time Complexity=O(1) for getRandom Operation .
Space Complexity=O(n).

Where, 'n' is the number of the node's in the given Linked List 'head'.