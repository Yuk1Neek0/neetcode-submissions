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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> dict;
        for(int i = 0; i < inorder.size(); i ++){

            dict[inorder[i]] = i;

        }
        return dfs(preorder,inorder,dict,0,preorder.size()- 1,0,inorder.size() - 1);
        
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &dict,int pl, int pr, int il, int ir ){

        if (pl > pr) return nullptr;
        TreeNode* node = new TreeNode(preorder[pl]);
        int index = dict[preorder[pl]];
        int leftsize = index - il;
        int rightsize = ir - index;
        node -> left = dfs(preorder,inorder,dict,pl + 1,pl + leftsize, il ,index - 1);
        node -> right = dfs(preorder,inorder,dict,pl + 1 +leftsize,pr, index + 1, ir);
        return node;
    }
};
