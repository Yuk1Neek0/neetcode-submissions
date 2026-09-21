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
        
        TreeNode* root = recursion(0,preorder.size()-1,0,preorder.size()-1,preorder,inorder);
        return root;

    }

    TreeNode* recursion(int inl, int inr, int l, int r, vector<int>& preorder, vector<int>& inorder){
        
        if(l > r) return nullptr;
        auto it = find(inorder.begin(),inorder.end(),preorder[l]);
        TreeNode* newnode = new TreeNode(preorder[l]);
        int index = it - inorder.begin();

        int leftlength = index - inl;
        int rightlength = inr - index;

        newnode -> left = recursion(inl,index - 1,l + 1, l + leftlength, preorder, inorder);
        newnode -> right = recursion(index + 1, inr, r - rightlength + 1, r, preorder, inorder);
        return newnode;
    }
};
