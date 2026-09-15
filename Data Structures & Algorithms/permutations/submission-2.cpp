class Solution {
public:
    vector<int> subres;
    vector<vector<int>> res;
    unordered_set<int> mark;
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }

        backtrack(0, nums.size(), nums);
        return res;

    }
    void backtrack(int n, int target, vector<int>& nums){

        if(n == target){

            res.push_back(subres);
            return;
        }

        for(int i = 0; i < target; i++){

            if(mark.count(nums[i]) != 0) continue;
            subres.push_back(nums[i]);
            mark.insert(nums[i]);
            backtrack(n+1 , target, nums);
            subres.pop_back();
            mark.erase(mark.find(nums[i]));

        }

    }
};
