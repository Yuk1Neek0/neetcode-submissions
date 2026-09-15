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
        unordered_map<Node*,Node*> mapping;
        Node* newnode = clone(mapping,node);
        return newnode;

    }

    Node* clone(unordered_map<Node*,Node*> &mapping, Node* node){

        if(mapping.contains(node)) return mapping[node];

        Node* nnode = new Node();
        nnode -> val = node -> val;
        mapping[node] = nnode;
        for(int i = 0; i< node -> neighbors.size() ;i++){

            nnode -> neighbors.push_back(clone(mapping,node -> neighbors[i]));

        }
        return nnode;

    }
};
