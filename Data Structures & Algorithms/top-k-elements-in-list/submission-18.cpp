class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> times;
        for(int &n : nums) times[n] ++;

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto const& time : times) bucket[time.second].push_back(time.first);

        vector<int> res;

        for(int i = nums.size(); i > 0; i --){

            if(bucket[i].empty()) continue;
            for(int j = 0; j < bucket[i].size(); j ++){

                res.push_back(bucket[i][j]);
                if(res.size() == k) return res;
 
            }

        }
        return res;
    }
};
