class Solution {
public:
    vector<vector<int>> res;
    vector<int> subres;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        backtrack(nums,0);
        return res;

    }

    void backtrack(vector<int>& nums, int n){

        if(n >= nums.size()){

            res.push_back(subres);
            return;

        }
        subres.push_back(nums[n]);
        backtrack(nums , n+1);
        subres.pop_back();

        backtrack(nums , n+1);

    }
};
