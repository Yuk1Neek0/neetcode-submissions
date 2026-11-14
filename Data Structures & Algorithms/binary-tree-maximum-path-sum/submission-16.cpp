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
    int maxPathSum(TreeNode* root) {
        int res = -1005;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* node, int &res){

        if(!node) return 0;
        int lmax = dfs(node -> left, res);
        int rmax = dfs(node -> right, res);

        int curmax = node -> val;
        if(lmax > 0) curmax += lmax;
        if(rmax > 0) curmax += rmax;
        res = max(res,curmax);

        return max(0,max(lmax,rmax)) + node -> val;

    }
};
