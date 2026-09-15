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
    int arr[1005] = {0};
    int n = 1;
    int kthSmallest(TreeNode* root, int k) {
        
        recursion(root);
        return arr[k];

    }
    void recursion(TreeNode* node){

        if(!node) return;
        recursion(node -> left);
        arr[n++] = node -> val;
        recursion(node -> right); 

    }
};
