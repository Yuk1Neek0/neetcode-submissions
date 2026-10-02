class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        unordered_set<int> used;
        vector<int> subres;
        vector<vector<int>> res;
        backtracking(nums,res,subres,used);
        return res;

    }

    void backtracking(vector<int>& nums,vector<vector<int>> &res,vector<int> &subres,unordered_set<int> &used){

        if(subres.size() == nums.size()) {

            res.push_back(subres);
            return;
            
        }

        for(int i = 0; i < nums.size(); i ++){

            if(used.contains(nums[i])) continue;

            used.insert(nums[i]);
            subres.push_back(nums[i]);
            backtracking(nums,res,subres,used);
            subres.pop_back();
            used.erase(nums[i]);

        }

    }
};
