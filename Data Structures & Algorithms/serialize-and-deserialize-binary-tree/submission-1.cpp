/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> que;
        if(!root) return "#";
        que.push(root);

        while(!que.empty()){

            int size = que.size();
            for(int i = 0; i< size; i ++){

                TreeNode* node = que.front();
                que.pop();

                if(!node) s.append("#,");
                else{

                    s.append(to_string(node -> val) + ",");
                    que.push(node -> left);
                    que.push(node -> right);

                }
            }

        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
    string tok;

    getline(ss, tok, ',');
    if (tok == "#") return nullptr;

    TreeNode* root = new TreeNode(stoi(tok));
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        TreeNode* node = que.front();
        que.pop();

        getline(ss, tok, ',');
        if (tok != "#") {
            node->left = new TreeNode(stoi(tok));
            que.push(node->left);
        }

        getline(ss, tok, ',');
        if (tok != "#") {
            node->right = new TreeNode(stoi(tok));
            que.push(node->right);
        }
        
    }
    return root;
    }
};
