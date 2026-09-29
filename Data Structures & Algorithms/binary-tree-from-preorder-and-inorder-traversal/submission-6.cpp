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
        
        unordered_map<int,int> mapping;

        for(int i = 0; i < inorder.size(); i++) mapping[inorder[i]] = i;
        return dfs(preorder,inorder,mapping,0,preorder.size()-1,0,inorder.size()-1);

    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mapping, int pl, int pr, int il, int ir){

        if(pl > pr || il > ir) return nullptr;

        int root = preorder[pl];
        int leftsize = mapping[root] - il;
        int rightsize = ir - mapping[root];

        TreeNode* node = new TreeNode(root);
        node -> left = dfs(preorder,inorder,mapping,pl + 1, pl + leftsize,il,il + leftsize - 1);
        node -> right = dfs(preorder,inorder,mapping,pr - rightsize + 1,pr, ir - rightsize + 1, ir);

        return node;

    }
};
