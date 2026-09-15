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
        
        if(!head || !head -> next || !head -> next -> next) return;

        ListNode* fast, *slow;

        slow = head;
        fast = head;
        while(fast != nullptr){

            if(!fast -> next || !fast -> next -> next) break;
            fast = fast -> next -> next;
            slow = slow -> next;

        }
        ListNode* mid = slow;
        ListNode* pre = slow -> next;
        while(pre != nullptr){

            ListNode* temp = pre -> next;
            pre -> next = slow;
            slow = pre;
            pre = temp;

        }

        ListNode* left = head, *right = slow;
        ListNode dummyhead;
        ListNode* f = &dummyhead;
        while(right != mid){

            f -> next = left;
            f = f -> next;
            left = left -> next;
            f -> next = right;
            right = right -> next;
            f = f -> next;

        }

        if(left == right) {

            f -> next = left;
            f = f -> next;
        }
        else{

            f -> next = left;
            f -> next -> next = right;
            f = f -> next -> next;
        }
        f -> next = nullptr;

        head = dummyhead.next;



    }
};
