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
        unordered_map<Node*,Node*> dict;
        return dfs(dict,node);
    }
    Node* dfs(unordered_map<Node*,Node*> &dict, Node* node){
        if(!node) return nullptr;
        if(dict.contains(node)) return dict[node];
        Node* newnode = new Node(node -> val);
        dict[node] = newnode;
        for(auto const& nei : node -> neighbors){

            newnode -> neighbors.push_back(dfs(dict,nei));

        }
        return newnode;

    }
};
