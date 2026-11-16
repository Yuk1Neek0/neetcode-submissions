class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<int> subres;
        vector<vector<int>> res;
        dfs(nums,target,subres,res,0,0);
        return res;

    }
    void dfs(vector<int>& nums, int target,vector<int> &subres, vector<vector<int>> &res, int sum, int n){

        if(sum >= target){

            if(sum == target) res.push_back(subres);
            return;

        }

        for(int i = n; i < nums.size(); i++){

            subres.push_back(nums[i]);
            dfs(nums,target,subres,res,sum + nums[i],i);
            subres.pop_back();

        }

    }
};
