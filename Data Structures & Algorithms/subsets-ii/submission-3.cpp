class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subres;
        backtracking(nums,res,subres,0);
        return res;

    }

    void backtracking(vector<int>& nums, vector<vector<int>> &res, vector<int> &subres, int n){

        //if(n >= nums.size()) return;
        res.push_back(subres);

        for(int i = n; i < nums.size(); i++){

            if(i > n)
                if(nums[i] == nums[i - 1]) continue;
            
            subres.push_back(nums[i]);
            backtracking(nums,res,subres,i + 1);
            subres.pop_back();
        }

    }
};
