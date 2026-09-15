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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return recursion(p,q);

    }

    bool recursion(TreeNode*p, TreeNode* q){

        if(p == nullptr || q == nullptr){

            if(p != nullptr || q != nullptr) return false;
            return true;

        }
        if(p -> val != q -> val) return false;
        if(!recursion(p -> left, q -> left) || !recursion(p -> right, q -> right)) return false;
        return true;
    }
};
