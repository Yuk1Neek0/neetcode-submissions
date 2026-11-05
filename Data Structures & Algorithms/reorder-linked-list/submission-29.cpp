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
        
        ListNode* end = head;
        int len = 1;

        while(end -> next){

            end = end -> next;
            len++;

        }
        if(len <= 2) return;


        ListNode* slow = head, *fast = head;
        while(fast && fast -> next){

            fast = fast -> next;
            if(!fast -> next) break;
            fast = fast -> next;
            slow = slow -> next;

        }

        ListNode* cur = slow -> next;
        slow -> next = nullptr;
        ListNode* pre = nullptr;
        while(cur){

            ListNode* temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;

        }

        ListNode dummyhead;
        ListNode* finger = &dummyhead;

        ListNode* l = head, *r = end;
        while(l){

            if(l){

                finger -> next = l;
                l = l -> next;
                finger = finger -> next;

            }
            if(r){

                finger -> next = r;
                r = r -> next;
                finger = finger -> next;

            }

        }

        head = dummyhead.next;
    }
};
