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
        

        ListNode dummy(0);
        ListNode *node;
        node = &dummy;

        if(head -> next == nullptr){

            return;

        }
        else if (head -> next -> next == nullptr) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast -> next != nullptr){

            slow = slow -> next;
            fast = fast -> next;
            if(fast -> next == nullptr) break;
            else fast = fast -> next;

        }

        ListNode* pre = nullptr;
        ListNode* cur = slow;

        while(cur != nullptr){

            ListNode* temp = cur;
            cur = cur -> next;
            temp -> next = pre;
            pre = temp;

        }

        ListNode* l = head;
        ListNode* r = fast;

        while(l != slow){
            
            ListNode* templ;
            ListNode* tempr;
            templ = l -> next, tempr = r -> next;
            node -> next = l;
            l -> next = r;
            node = r;
            l = templ;
            r = tempr;

        }
        node -> next = l;
        if(l != r) node ->next ->next = r;


    }
};
