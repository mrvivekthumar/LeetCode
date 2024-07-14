/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(nums[i]);
        
        ListNode* fast = head;
        ListNode* slow = nullptr;
        ListNode* nxtf = nullptr;
        
        while(fast != nullptr) {
            if (st.count(fast -> val)) {
                fast = fast -> next;
                if (slow != nullptr) {
                    slow -> next = fast;
                
                }
            } else {
                if (nxtf == nullptr)
                nxtf = fast;
                if (slow != nullptr) {
                    slow = slow -> next;
                } else {
                    slow = fast;
                }
                fast = fast -> next;
            }
        }
        return nxtf;
    }
};