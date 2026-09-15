class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> maxsum(nums.size(),-10005);

        for(int i = 0; i < nums.size(); i++){

            if(i == 0) maxsum[i] = max(maxsum[i], nums[i]);
            else
            maxsum[i] = max(nums[i], nums[i] + maxsum[i - 1]);
        
        }

        int res = -10005;
        for(int n : maxsum){

            if(res < n) res = n;

        }
        return res;
    }   
};
