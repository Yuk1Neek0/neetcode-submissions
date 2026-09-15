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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        
       recursion(root);
       return res;

    }

    int recursion(TreeNode *root){

        if(root == nullptr) return -1;

        int l = recursion(root -> left) + 1;
        int r = recursion(root -> right) + 1;
        res = max(res, l + r);

        return l > r ? l : r;

    }
};
