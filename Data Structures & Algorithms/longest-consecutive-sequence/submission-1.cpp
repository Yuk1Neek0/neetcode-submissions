class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> record;

        for(int i = 0; i < nums.size(); i++){
            
            if(!record[nums[i]]){

                record[nums[i]] = record[nums[i] + 1] + record[nums[i] - 1] + 1;
                record[nums[i] - record[nums[i] - 1]] = record[nums[i]];
                record[nums[i] + record[nums[i] + 1]] = record[nums[i]];
            }

        }

        int max = 0;
        for(const auto & it : record){

            if(max < it.second) max = it.second;

        }

        return max;

    }
};
