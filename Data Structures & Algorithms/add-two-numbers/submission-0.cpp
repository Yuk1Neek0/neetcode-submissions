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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy = ListNode(0);
        ListNode *n1 = l1, *n2 = l2 , *cur = &dummy;
        int carry = 0;

        while(n1 != nullptr || n2 != nullptr || carry != 0){

            int v1 = (n1 != nullptr) ? n1 -> val : 0;
            int v2 = (n2 != nullptr) ? n2 -> val : 0;

            int sum = v1 + v2 + carry;
            cur -> next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur -> next;
            n1 = (n1 != nullptr) ? n1 -> next : nullptr;
            n2 = (n2 != nullptr) ? n2 -> next : nullptr;
        }

        return dummy.next;

    }
};
