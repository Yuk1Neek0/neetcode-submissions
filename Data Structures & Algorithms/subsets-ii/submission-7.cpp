class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subres;
        vector<vector<int>> res;

        backtracking(nums,subres,res,0);

        return res;
    }

    void backtracking(vector<int>& nums, vector<int> &subres, vector<vector<int>> &res, int n){

        if(n > nums.size()) return;
        res.push_back(subres);

        for(int i = n; i < nums.size(); i ++){

            if(i > n) if(nums[i] == nums[i - 1]) continue;

            subres.push_back(nums[i]);

            backtracking(nums,subres,res,i + 1);

            subres.pop_back();

        }

    }
};
