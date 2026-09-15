    class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            
            vector<vector<int>> res;
            vector<int> subres;
            backtracking(res,subres,nums,target,0,0);

            return res;
    
        }

        void backtracking(vector<vector<int>> &res,vector<int> & subres,vector<int> &nums, int target, int sum, int n){

            if(sum == target){

                res.push_back(subres);
                return;

            }
            if(sum > target) return;

            for(int i = n; i < nums.size(); i++){

                sum += nums[i];
                subres.push_back(nums[i]);
                backtracking(res,subres,nums,target,sum,i);

                subres.pop_back();
                sum -= nums[i];

            }


        }
    };
