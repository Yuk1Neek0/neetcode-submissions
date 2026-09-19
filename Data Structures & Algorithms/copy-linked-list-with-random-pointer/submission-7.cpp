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
        
        
        unordered_map<Node*,Node*> mapping;
        Node* newnode = copy(mapping,head);

        return newnode;

    }

    Node* copy(unordered_map<Node*,Node*> &mapping,Node* node){

        if(!node) return nullptr;
        if(mapping.contains(node)) return mapping[node];

        Node* newnode = new Node(node -> val);
        mapping[node] = newnode;
        newnode -> random = copy(mapping,node -> random);
        newnode -> next = copy(mapping,node -> next);
        return newnode;

    }
};
