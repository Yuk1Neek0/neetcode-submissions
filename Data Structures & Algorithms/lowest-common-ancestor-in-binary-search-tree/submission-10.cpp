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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int g = max(p -> val, q -> val);
        int l = min(p -> val, q -> val);

        if(root -> val >= l && root -> val <= g) return root;
        if(root -> val > g) return lowestCommonAncestor(root -> left, p, q);
        if(root -> val < l) return lowestCommonAncestor(root -> right, p, q);
    }
};
