class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(),0);
        vector<int> dp2(nums.size(),0);
        dp1[0] = nums[0];
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size()- 1; i++){
            
            if(i == 0) dp1[i] = nums[i];
            else if(i == 1) dp1[i] = max(nums[i],nums[i-1]);
            else dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);

        }

        for(int i = 1; i < nums.size(); i++){

            if(i == 1) dp2[i] = nums[i];
            else dp2[i] =  max(dp2[i - 1], dp2[i - 2] + nums[i]);

        }
        int max1 = 0,max2 = 0;
        for(int n : dp1) max1 = max(max1,n);
        for(int n : dp2) max2 = max(max2,n);

        return max(max1,max2);
        

    }
};
