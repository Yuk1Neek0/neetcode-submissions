class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -10005;
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){

            if(sum >= 0){

                sum += nums[i];
                res = max(res,sum);

            }
            else{

                sum = nums[i];
                res = max(sum,res);

            }

        }
        return res;
    }
};
