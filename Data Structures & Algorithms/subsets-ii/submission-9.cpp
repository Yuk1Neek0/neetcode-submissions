class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subres; 
        sort(nums.begin(),nums.end());
        dfs(res,subres,nums,0);

        return res;


    }
    void dfs(vector<vector<int>> &res, vector<int> &subres, vector<int>& nums, int n){

        res.push_back(subres);
        if(n >= nums.size()) return;

        for(int i = n; i < nums.size(); i ++){

            if(i > n) if(nums[i] == nums[i - 1]) continue;

            subres.push_back(nums[i]);
            dfs(res,subres,nums,i + 1);
            subres.pop_back();

        }

    }
};
