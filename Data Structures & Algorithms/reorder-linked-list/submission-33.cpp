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
        
        int size = 1;
        ListNode* tail = head;
        while(tail -> next){

            size ++;
            tail = tail -> next;

        }
        if(size <= 2) return ;
        ListNode* fast = head, *slow = head;
        while(fast){

            fast = fast -> next;
            if(!fast) break;
            fast = fast -> next;
            if(!fast) break;
            slow = slow -> next;

        }

        ListNode *mid = slow -> next;
        slow -> next = nullptr;

        ListNode* cur = mid;
        ListNode* prev = nullptr;
        while(cur){

            ListNode* temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;

        }

        ListNode dummyhead;
        ListNode* finger = &dummyhead;
        ListNode* l = head, *r = tail;
        while(l && r){

            finger -> next = l;
            l = l -> next;
            finger = finger -> next;
            finger -> next = r;
            r = r -> next;
            finger = finger -> next;
        }
        if(l){

            finger -> next= l;

        }

        head = dummyhead.next;
        
    }
};
