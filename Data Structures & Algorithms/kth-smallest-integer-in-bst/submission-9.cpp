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
        
        int res = -1, n = 0;

        dfs(root,k,res,n);

        return res;

    }

    void dfs(TreeNode* root, int k, int &res, int &n){

        if(!root) return;
        if(res != -1) return;
        if(root -> left) dfs(root -> left, k, res, n);
        n ++;
        if(n == k) res = root -> val;
        if(root -> right) dfs(root -> right, k, res, n);

    }
};
