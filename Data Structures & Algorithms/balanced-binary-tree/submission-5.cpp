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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        dfs(root,is_balanced);
        return is_balanced;
    }
    int dfs(TreeNode* node, bool & is_balanced){
        if(!is_balanced) return -1;
        if(!node) return 0;
        int ldepth = dfs(node -> left,is_balanced);
        int rdepth = dfs(node -> right,is_balanced);
        int depth = max(ldepth,rdepth) + 1;

        if(abs(ldepth - rdepth) > 1){

            is_balanced = false;
            return -1;

        }
        return depth;


 
    }
};
