class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        dfs(nums,target,res,subres,0,0);
        return res;
    }
    void dfs(vector<int>& nums, int target, vector<vector<int>> &res, vector<int> &subres, int n, int sum){

        if(sum >= target || n >= nums.size()){

            if(sum == target) res.push_back(subres);
            return;

        }

        for(int i = n; i < nums.size(); i++){

            subres.push_back(nums[i]);
            dfs(nums,target,res,subres,i,sum + nums[i]);
            subres.pop_back();

        }

    }
};
