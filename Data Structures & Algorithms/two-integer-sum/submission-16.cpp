class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> pos;

        for(int i = 0 ; i < nums.size(); i ++){

            if(pos.contains(target - nums[i])) return {pos[target-nums[i]],i};

            pos[nums[i]] = i;

        }
        
        return {};
    }
};
