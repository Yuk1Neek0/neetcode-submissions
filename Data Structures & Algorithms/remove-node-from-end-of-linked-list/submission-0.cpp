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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        head = revList(head);
        ListNode* node = head;
        if(n == 1){
            head = head -> next;
            return revList(head);
        }
        for(int i = 2; i < n ;i++){

            node = node -> next;

        }

        node -> next = node -> next -> next;
        return revList(head);

    }

    ListNode* revList(ListNode* head){

        ListNode* pre = nullptr, *cur = head;

        while(cur != nullptr){

            ListNode* temp = cur;
            cur = cur -> next;
            temp -> next = pre;
            pre = temp;

        }

        return pre;

    }
};
