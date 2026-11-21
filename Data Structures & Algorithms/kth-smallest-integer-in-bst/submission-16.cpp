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
        int res = -1;
        int nth = -1;
        dfs(root,k,res,nth);
        return res;
    }
    void dfs(TreeNode* node, int k, int &res, int &nth){
        
        if(!node || res != -1){

            if(nth == -1) nth = 1;
            return;

        }
        dfs(node -> left, k, res, nth);
        if(nth != -1){

            if(nth == k){

                res = node -> val;

            }
            nth ++;

        }
        dfs(node -> right,k,res,nth);

    }
};
