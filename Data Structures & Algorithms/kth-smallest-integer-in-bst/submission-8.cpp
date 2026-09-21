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
    int kthSmallest(TreeNode* root, int k) {
        
        int res = 0, n = -1;
        recursion(root, res, n , k);

        return res;

    }

    void recursion(TreeNode* root, int &res, int &n, int k){

    if(!root) {
        
        if(n == -1) n = 0;
        return;

    }

    
    recursion(root -> left, res, n, k);
    if(n != -1) n ++;
    if(n == k)  res = root -> val;
    recursion(root -> right,res,n,k);
    }
};