class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> bucket(nums.size() + 5);

        unordered_map<int,int> freq;

        for(auto& n : nums){

            freq[n] ++;

        }

        for(auto &n : freq){

            bucket[n.second].push_back(n.first);

        }

        vector<int> res;

        for( int f = nums.size(); f >= 0 && res.size() <= k; f--){

            for(auto&n : bucket[f]){

                res.push_back(n);
                if(res.size() == k) return res;

            }

        }
        return res;

    }
};

/*
    Top K Frequent Elements.
    这题思路断了 20min 没做出来 没有想到该怎么从map的尾部往前读。
*/
