class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        unordered_map<int,int> record; //a record that stores pair num,index.

        for(int i = 0; i < nums.size(); i++ ){

            record[nums[i]] = i;

        }

        for( int i = 0; i < nums.size(); i++ ){

            if( record[target - nums[i]] && i != record[target - nums[i]]) {

                if(record[target - nums[i]] > i){

                    res.push_back(i);
                    res.push_back(record[target - nums[i]]);
                    return res;

                }
                else {

                    res.push_back(record[target - nums[i]]);
                    res.push_back(i);
                    return res;

                }

            }
            
        }

        return res;
    }
};
