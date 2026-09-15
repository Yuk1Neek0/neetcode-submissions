class Solution {
public:
    vector<vector<int>> res;
    vector<int> subres;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int sum, int n){

        if(sum >= target || n >= nums.size()){

            if(sum == target) res.push_back(subres);
            return;

        }
        subres.push_back(nums[n]);
        backtrack(nums,target,sum + nums[n], n);
        subres.pop_back();

        backtrack(nums,target,sum, n+1);

    }
};
