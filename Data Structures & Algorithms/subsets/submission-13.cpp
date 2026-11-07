class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subres;
        dfs(res,nums,subres,0);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> & subres, int n){

        res.push_back(subres);

        if(n >= nums.size()) return;

        for(int i = n; i < nums.size(); i ++){

            subres.push_back(nums[i]);
            dfs(res,nums,subres, i + 1);
            subres.pop_back();

        }

    }
};
