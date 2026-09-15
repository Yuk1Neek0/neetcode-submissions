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

        ListNode* fast, *slow;
        fast = head;
        slow = head;

        while(fast){

            if(! fast -> next || ! fast -> next -> next) break;
            fast = fast -> next -> next;
            slow = slow -> next;

        } 
        
        ListNode* prev = nullptr, *cur = slow -> next;
        slow -> next = nullptr;
        while(cur){

            ListNode* temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;

        }

        ListNode dummyhead;
        ListNode* finger = &dummyhead;
        ListNode* left = head, *right = prev;

        while(right){

            finger -> next = left;
            left = left -> next;
            finger = finger -> next;
            finger -> next = right;
            right = right -> next;
            finger = finger -> next;

        }

        finger -> next = left;
        head = dummyhead .next;

        
 

    }
};
