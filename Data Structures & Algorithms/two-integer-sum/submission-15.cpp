class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mapping;

        for(int i = 0; i < nums.size(); i++){

            if(mapping.contains(target - nums[i])) return{mapping[target - nums[i]], i};
            mapping[nums[i]] = i;    

        }

        return {};

    }
};
