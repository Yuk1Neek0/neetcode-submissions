class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> seen;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++ ){

            if(seen.find(target - nums[i]) != seen.end()){

                res.push_back(seen[target - nums[i]]);
                res.push_back(i);
                return res;

            }

            seen[nums[i]] = i;

        }
        return res;

    }
};

/*
Two Sum AC 19:37 我没想到这道题会有这么多坑，花了很多时间debug。 一开始没注意到 写的是res.push_back(record[i])而并非 res.push_back(record[target - nums[i]]); 还有，没有对i!=j进行判断，也没有在得到答案的第一时间return，产生了重复存储答案。
*/
