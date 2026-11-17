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
        dfs(node,dict);
        return dict[node];
    }
    Node* dfs(Node* node,unordered_map<Node*,Node*> &dict){
        if(!node) return nullptr;
        if(dict[node]) return dict[node];

        Node* newnode = new Node();
        newnode -> val = node -> val;
        dict[node] = newnode;
        for(auto const& neigh : node -> neighbors){

            newnode -> neighbors.push_back(dfs(neigh,dict));

        }
        return newnode;

    }
};
