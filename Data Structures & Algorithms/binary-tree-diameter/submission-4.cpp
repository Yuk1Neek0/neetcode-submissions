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
    int diameterOfBinaryTree(TreeNode* root) {
        int Max = 0;
        recursion(root,Max);
        return Max;
    }

    int recursion(TreeNode* root, int &Max){

        if(!root) return 0;

        int downleft = recursion(root -> left, Max);
        int downright = recursion(root -> right, Max);

        Max = max(Max,downleft + downright);
        return 1 + max(downleft,downright);

    }
};
