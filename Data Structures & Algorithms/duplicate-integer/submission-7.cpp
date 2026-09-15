class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        if(nums.size() == 1 ) return false;

        for(int i = 0; i < nums.size(); i++){

            if(record.find(nums[i]) != record.end()) return true;

            record.insert(nums[i]); 
            
        }

        return false;

    }
};