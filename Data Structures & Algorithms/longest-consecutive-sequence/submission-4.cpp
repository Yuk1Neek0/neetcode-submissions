class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){

            if(map[nums[i]]) continue;

            map[nums[i]] = map[nums[i] - 1] + map[nums[i] + 1] + 1;

            map[nums[i] - map[nums[i] - 1]] = map[nums[i]];
            map[nums[i] + map[nums[i] + 1]] = map[nums[i]];

            if(map[nums[i]] > res) res = map[nums[i]];
        }

        return res;
    }
};
