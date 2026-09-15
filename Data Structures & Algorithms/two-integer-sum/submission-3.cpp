class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            
            int diff=target-nums[i];
            if(map.count(diff)&&map[diff]!=i){
                res = {map[diff],i};
                
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
