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

        ListNode dummyhead;
        ListNode* finger = &dummyhead;
        bool flag = false;
        while(l1 && l2){

            int sum = l1 -> val + l2 -> val;
            l1 = l1 -> next;
            l2 = l2 -> next;
            ListNode* node = new ListNode();

            if(flag == true){

                sum += 1;
                flag = false;

            }
            if(sum >9){

                flag = true;
                sum = sum % 10;

            }

            node -> val = sum;
            finger -> next = node;
            finger = finger -> next;

        }

        while(l1){

           ListNode* node = new ListNode();
           int num = l1 -> val;
           l1 = l1 -> next;
           if(flag == true){

                num ++;
                flag = false;

           } 

           if(num > 9){

            flag = true;
            num %= 10;

           }
           node -> val = num;
           finger -> next = node;
           finger = finger -> next;

        }
        while(l2){

           ListNode* node = new ListNode();
           int num = l2 -> val;
           l2 = l2 -> next;
           if(flag == true){

                num ++;
                flag = false;

           } 

           if(num > 9){

            flag = true;
            num %= 10;

           }
           node -> val = num;
           finger -> next = node;
           finger = finger -> next;

        } 

        if(flag){

            ListNode* node = new ListNode(1);
            finger -> next = node;
            finger = finger -> next;

        }
        return dummyhead .next;

    }

};
