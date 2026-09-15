class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subres;
        recursion(nums,res,subres,0);
        return res;
    }

    void recursion(vector<int> &nums, vector<vector<int>> &res, vector<int> &subres, int n){

        res.push_back(subres);

        for(int i = n; i < nums.size(); i++){

            subres.push_back(nums[i]);
            recursion(nums,res,subres,i + 1);
            subres.pop_back();
        }

    }
};
