class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int,int> freq;

        for(int n : nums) freq[n] ++;
        for(auto const& n : freq) bucket[n.second].push_back(n.first);

        vector<int> res;

        for(int i = nums.size(); i > 0; i --){

            if(bucket[i].empty()) continue;
            for(int n : bucket[i]){

                res.push_back(n);
                if(res.size() >= k) return res;

            }

        }
        return res;
         
    }
};
