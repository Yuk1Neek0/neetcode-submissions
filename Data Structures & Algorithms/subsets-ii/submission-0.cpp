class Solution {
public:
    vector<int> subres;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums.size(),nums);
        return res;
    }

    void backtrack(int n, int size, vector<int>& nums){

        if(n == size){

            res.push_back(subres);
            return;

        }

        subres.push_back(nums[n]);
        n++;
        backtrack(n, size, nums);
        subres.pop_back();
        n--;

        while(n+1 < size && nums[n] == nums[n+1]) n++;
        backtrack(n + 1,size,nums);
    }
};
