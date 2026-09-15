class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> ele(nums.begin(),nums.end());

        int res = 0;
        for(auto&n : ele){

            if(ele.contains(n - 1)) continue;

            int len = 1;
            while(ele.contains(n + len)) len ++;

            if(res < len) res = len;

        }

        return res;

    }
};
/*Longest Consecutive Sequence
这题更是投降 没有思路
*/
