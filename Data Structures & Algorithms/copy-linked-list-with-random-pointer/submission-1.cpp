/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> OldToNew;
        OldToNew[nullptr] = nullptr;
        Node* cur = head;

        while(cur != nullptr){

            if(OldToNew.find(cur) == OldToNew.end()){

                OldToNew[cur] = new Node(0);

            }
            
            OldToNew[cur] -> val = cur -> val;

            if(OldToNew.find(cur -> next) == OldToNew.end()){

                OldToNew[cur -> next] = new Node(0);

            }
            OldToNew[cur] -> next = OldToNew[cur -> next]; 
 
            if(OldToNew.find(cur -> random) == OldToNew.end()){

                OldToNew[cur -> random] = new Node(0);

            }
            OldToNew[cur] -> random = OldToNew[cur -> random];
            cur = cur -> next;
        }
            return OldToNew[head];
    }
};
