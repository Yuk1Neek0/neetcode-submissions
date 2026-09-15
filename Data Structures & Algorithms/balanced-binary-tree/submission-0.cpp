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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        
        recursion(root);
        return res;

    }

    int recursion(TreeNode* root){

        if(root == nullptr) return 0;

        int l = recursion(root -> left) + 1;
        int r = recursion(root -> right) + 1;

        if(abs(l - r ) >1) res = false;
        return max(l,r);
    }
};
