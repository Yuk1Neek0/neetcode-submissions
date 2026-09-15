class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        for(int n : nums){

            freq[n] ++;

        }

        vector<vector<int>> fbucket(nums.size() + 5);

        for(auto& i : freq){

            fbucket[i.second].push_back(i.first);

        }

        int numk = 0;
        vector<int> res;
        for(int i = nums.size(); i > 0 && numk < k; i --){

            for(int n : fbucket[i]){

                res.push_back(n);
                numk ++;
                if(numk == k) return res;

            }

        }

        return res;

    }
};
