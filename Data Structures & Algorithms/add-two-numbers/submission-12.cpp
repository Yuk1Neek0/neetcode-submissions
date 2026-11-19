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
        bool flag = false;
        ListNode dummyhead;
        ListNode* finger = &dummyhead;

        while(l1 && l2){

            int sum = l1 -> val + l2 -> val;
            if(flag){

                sum += 1;
                flag = false;

            }
            if(sum >= 10){

                sum -= 10;
                flag = true;

            }
             ListNode* node = new ListNode(sum);
            finger -> next = node;
            finger = finger -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1){

            int value = l1 -> val;
            if(flag){

                value ++;
                flag = false;

            }
            if(value >= 10){

                value -= 10;
                flag = true;

            }
            ListNode * node = new ListNode(value);
            finger -> next = node;
            finger = finger -> next;
            l1 = l1 -> next;
        }

        while(l2){

            int value = l2 -> val;
            if(flag){

                value ++;
                flag = false;

            }
            if(value >= 10){

                value -= 10;
                flag = true;

            }
            ListNode * node = new ListNode(value);
            finger -> next = node;
            finger = finger -> next;
            l2 = l2 -> next;
        }
        if(flag){

            ListNode* node = new ListNode(1);
            finger -> next = node;

        }
        return dummyhead.next;
    }
};
