class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0;
        for(int i = 0; i <= nums.size(); i ++) t ^= i;
        for(int &n : nums) t ^= n;
        return t;

    }
};
/*
Missing Number AC 3min time:O(n) space:O(1)
*/