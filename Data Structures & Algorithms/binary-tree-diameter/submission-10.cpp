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
        int res = 0;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int &res){

        if(!root) return 0;

        int leftdepth = dfs(root -> left,res);
        int rightdepth = dfs(root -> right,res);
        res = max(res,leftdepth + rightdepth);

        return max(leftdepth,rightdepth) + 1;

    }
};
/*
Diameter of Binary Tree AC 8min time:O(n) space:O(n)
*/