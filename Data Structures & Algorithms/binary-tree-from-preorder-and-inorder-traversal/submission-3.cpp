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
        
        unordered_map<int,int> inmap;
        for(int i = 0; i < inorder.size(); i++) inmap[inorder[i]] = i;
        TreeNode* root = new TreeNode();

        root = dfs(preorder,inorder,0,preorder.size() - 1, 0, inorder.size() - 1, inmap);
        return root;

    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl,int pr,int il, int ir, unordered_map<int,int> &inmap){
        if(ir < ir || pr < pl) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[pl]);
        int index = inmap[node -> val];

        int leftsize = index - il;
        int rightsize = ir - index;

        node -> left = dfs(preorder,inorder,pl + 1, pl + leftsize, il, il + leftsize - 1, inmap);
        node -> right = dfs(preorder,inorder,pr - rightsize + 1, pr, ir - rightsize + 1, ir, inmap );

        return node;

    }
};
