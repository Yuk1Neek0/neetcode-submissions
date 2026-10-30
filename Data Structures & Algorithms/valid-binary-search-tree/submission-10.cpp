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
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MAX,INT_MIN);
    }

    bool dfs(TreeNode* node, int maxv, int minv){

        if(!node) return true;

        if(node -> val >= maxv || node -> val <= minv) return false;

        return dfs(node -> left, node -> val, minv) && dfs(node -> right, maxv, node -> val);

    }
};
