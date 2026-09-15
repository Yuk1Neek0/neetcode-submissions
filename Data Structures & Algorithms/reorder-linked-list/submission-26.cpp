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
    void reorderList(ListNode* head) {
        
        ListNode dummyhead;
        ListNode* finger = &dummyhead;

        ListNode* slow = head, *fast = head;

        while(fast && fast -> next && fast ->next -> next){

            slow = slow -> next;
            fast = fast ->next -> next;
        
        }

        ListNode* cur = slow -> next;
        slow -> next = nullptr;
        slow = cur;

        ListNode* prev = nullptr;

        while(cur){

            ListNode* temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;

        }

        ListNode* left = head, *right = prev;

        while(right){

            finger -> next = left;
            left = left -> next;
            finger = finger -> next;
            finger -> next = right;
            right = right -> next;
            finger = finger -> next;

        }
        if(left) finger -> next = left;

        head = dummyhead . next;

    }
};
