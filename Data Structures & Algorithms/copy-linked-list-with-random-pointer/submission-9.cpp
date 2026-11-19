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
        unordered_map<Node*,Node*> dict;
        return dfs(head,dict);
    }

    Node* dfs(Node* node, unordered_map<Node*,Node*>& dict ){
        if(!node) return nullptr;
        if(dict.contains(node)) return dict[node];
        Node* newnode = new Node(node -> val);
        dict[node] = newnode;
        newnode -> next = dfs(node -> next, dict);
        newnode -> random = dfs(node -> random,dict);
    
        return newnode;
    }
};
