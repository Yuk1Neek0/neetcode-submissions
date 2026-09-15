/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node) return nullptr;
        unordered_map<Node*, Node*> been;
        clone(node,been);
        return been[node];

    }

    Node* clone (Node* node, unordered_map<Node*,Node*> &been){

        if(been.contains(node)) return been[node];
        Node* nnode = new Node(node -> val);
        been[node] = nnode;
        for(auto& n : node->neighbors){
            
            nnode->neighbors.push_back(clone(n,been));

        }
        return nnode;

    }
};
