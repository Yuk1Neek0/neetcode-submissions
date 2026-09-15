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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root == nullptr) return res;

        que.push(root);
        while(!que.empty()){
            
            vector<int> subres;
            int size = que.size();
            for(int i = 0; i < size; i++){

                TreeNode *temp = que.front();
                que.pop();

                if(temp -> left != nullptr) que.push(temp -> left);
                if(temp -> right != nullptr) que.push(temp -> right);
                subres.push_back(temp -> val);

            }
            res.push_back(subres);


        }
        return res;
 
    }
};
