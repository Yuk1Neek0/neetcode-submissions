class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subres;

        dfs(res,subres,nums,0,0,target);
        return res;
        
    }
    void dfs(vector<vector<int>> &res, vector<int> &subres, vector<int> &nums, int n, int sum, int & target){

        if(sum >= target){

            if(sum == target) res.push_back(subres);
            return;
        }
        if(n >= nums.size()) return;
        for(int i = n; i < nums.size(); i ++){

            subres.push_back(nums[i]);
            dfs(res,subres,nums,i,sum + nums[i], target);
            subres.pop_back();
        }

    }
};
