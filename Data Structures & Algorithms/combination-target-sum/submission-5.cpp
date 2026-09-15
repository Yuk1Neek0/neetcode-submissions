class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        vector<int> subres;

        backtracking(nums,target,0,0,subres,res);

        return res;

    }

    void backtracking(vector<int> nums, int target, int sum, int n, vector<int> &subres, vector<vector<int>> &res){

        if(sum > target) return;
        if(sum == target) res.push_back(subres);

        for(int i = n; i < nums.size(); i++ ){

            sum += nums[i];
            subres.push_back(nums[i]);
            backtracking(nums,target,sum,i,subres,res);
            sum -= nums[i];
            subres.pop_back();

        }

    }
};
