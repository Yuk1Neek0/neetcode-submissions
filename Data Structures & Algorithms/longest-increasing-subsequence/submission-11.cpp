class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> dp(nums.size(),1);

      for(int i = 0; i < nums.size(); i ++){

        int maxlen = 1;
        for(int j = 0; j < i; j ++){
            
            if(nums[i] > nums[j])
            maxlen = max(maxlen,dp[j] + 1);

        }
        dp[i] = maxlen;

      }
      int res = 1;
      for(int i = 0; i < dp.size(); i ++)
      res = max(res,dp[i]);
      return res;
    }
};
