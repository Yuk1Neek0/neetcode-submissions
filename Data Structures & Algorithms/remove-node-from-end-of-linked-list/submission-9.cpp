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
        ListNode dummyhead;
        dummyhead.next = head;
        ListNode* nnode = &dummyhead;
        ListNode* end = &dummyhead;
       
        for(int i = 1; i<=n ; i++){

            end = end -> next;

        }

        while(end-> next){

            nnode = nnode -> next;
            end = end -> next;

        }

        nnode -> next = nnode -> next -> next;
        return dummyhead.next;    
        
    }
};
