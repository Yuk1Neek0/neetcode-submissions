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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head, *slow = head;
        if(!head) return false;
        if(!head -> next) return false;

        fast = head -> next -> next;
        slow = head -> next;
        while(fast){

            if(fast == slow) return true;

            fast = fast -> next;
            if(!fast) return false;
            fast = fast -> next;
            
            slow = slow -> next;

        }
        return false;
    }
};
