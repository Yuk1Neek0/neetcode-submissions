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
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mapping;
        Node* finger = head;
        while(finger){

            Node* node = new Node(finger -> val);
            mapping[finger] = node;

            finger = finger -> next;

        }

        finger = head;
        while(finger){

            mapping[finger] -> next = mapping[finger -> next];
            mapping[finger] -> random = mapping[finger -> random];
            finger = finger -> next;

        }

        return mapping[head];

    }
};
