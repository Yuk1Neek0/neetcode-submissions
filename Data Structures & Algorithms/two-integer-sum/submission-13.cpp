class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mapnums;

        for(int i = 0; i < nums.size(); i ++){

            mapnums[nums[i]] = i;

        }

        for(int i = 0; i < nums.size(); i++){

            if(mapnums.contains(target - nums[i])){

                if(mapnums[target-nums[i]] != i){

                    return {i,mapnums[target - nums[i]]};

                }

            }

        }

        return {};

    }
};
