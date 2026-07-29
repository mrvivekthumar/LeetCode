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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* temp = head;
    //     ListNode* prev = NULL;
    //     ListNode* front;

    //     while(temp !=  NULL){
    //         front = temp -> next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = front;
    //     }
    //     return prev;
    // }

    // Recurstion Method
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        return recurstionMethod(temp);
    }

    ListNode* recurstionMethod(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* newHead = recurstionMethod(head->next);

        // ListNode* travel = newHead;
        // while(travel-> next != NULL ){
        //     travel = travel->next;
        // }

        // temp-> next = NULL;
        // travel->next = temp;

        // Second method
        ListNode* front = head->next;
        
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};