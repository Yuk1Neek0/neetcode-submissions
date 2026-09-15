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
    int res = 0;
    int goodNodes(TreeNode* root) {
        
        isgood(root, root -> val);
        return res;

    }

    void isgood(TreeNode* node, int max){

        if(node -> val >= max){

            res++;
            if(node -> left) isgood(node -> left , node -> val);
            if(node -> right) isgood(node -> right , node -> val);

        }
        else {

            if(node -> left) isgood(node -> left , max);
            if(node -> right) isgood(node -> right , max);

        }

    }
};
