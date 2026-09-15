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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return head;
        ListNode* l = head, *r = head -> next;
        ListNode* h = head;
        while(r != NULL){

            ListNode* temp = r;
            r = r -> next;

            temp -> next = l;
            l = temp;

        }
        h -> next = NULL;
        return l;

    }
};
