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
        
        int res = INT_MIN;
        dfs(root,res);
        return res;

    }
    int dfs(TreeNode* root, int& res){

        if(!root) return 0;
        int leftmax = dfs(root -> left, res);
        int rightmax = dfs(root -> right, res);

        int maxlen = root -> val;
        if(leftmax > 0) maxlen += leftmax;
        if(rightmax > 0) maxlen += rightmax;

        res = max(res,maxlen);
        return root -> val + max(0,max(leftmax,rightmax));

    }
};
