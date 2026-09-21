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
        
        if(!root) return true;
        bool isbalanced = true;

        height(root,isbalanced);
        return isbalanced;
    

    }

    int height(TreeNode* root, bool &isbalanced){
        if(!root) return 0;
        if(!isbalanced) return -1;

        int lefth = height(root -> left,isbalanced);
        int righth = height(root -> right,isbalanced);

        int maxh = 1 + max(lefth,righth);

        if(abs(lefth - righth) > 1) isbalanced = false;
        return maxh;
    } 

};
