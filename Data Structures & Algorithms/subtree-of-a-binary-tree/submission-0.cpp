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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == nullptr || subRoot == nullptr){
   
            if(root != nullptr || subRoot != nullptr) return false;

        }

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int size = que.size();
            for(int i = 0; i < size; i++){

                TreeNode* node = que.front();
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
                que.pop();
                if(isSame(node,subRoot)) return true; 

            }

        }
        return false;

    }

    bool isSame(TreeNode* root, TreeNode* subRoot){

        if(root == nullptr || subRoot == nullptr){
            
            if(root != nullptr || subRoot != nullptr) return false;
            return true;

        }

        if(root -> val != subRoot -> val) return false;
        if(!isSame(root -> left, subRoot -> left) || !isSame(root -> right, subRoot -> right)) return false;
        return true;

    }
};
