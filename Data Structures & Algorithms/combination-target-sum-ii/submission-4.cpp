class Solution {
public:
    vector<vector<int>> res;
    vector<int> subres;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0);
        return res;
    }

    void backtrack(vector<int> candidates, int target, int sum, int n){

        if(sum >= target || n >= candidates.size()){

            if(sum == target) res.push_back(subres);
            return;

        }
        subres.push_back(candidates[n]);
        backtrack(candidates,target,sum+candidates[n],n+1);
        subres.pop_back();

        while(n+1 < candidates.size() && candidates[n] == candidates[n+1]) n++;
        backtrack(candidates,target,sum,n+1);

    }
};
