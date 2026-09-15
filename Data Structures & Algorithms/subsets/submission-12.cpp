class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subres;
        vector<vector<int>> res;
        backtracking(nums,subres,res,0);

        return res;
    }

    void backtracking(vector<int>& nums, vector<int> &subres, vector<vector<int>> &res, int n){

        res.push_back(subres);

        for(int i = n; i < nums.size(); i++){

            subres.push_back(nums[i]);
            backtracking(nums,subres,res,i + 1);
            subres.pop_back();
        
        }

    }
};
