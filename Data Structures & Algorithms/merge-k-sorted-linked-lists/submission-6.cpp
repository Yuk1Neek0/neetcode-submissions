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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<>> que;
        for(auto const& l : lists) if(l) que.push({l->val,l});

        ListNode dummyhead ;
        ListNode* finger = &dummyhead;

        while(!que.empty()){

            ListNode* node = que.top().second;
            que.pop();

            finger -> next = node;
            finger = finger -> next;

            if(node -> next) que.push({node->next -> val,node -> next});

        }

        return dummyhead.next;

    }
};
