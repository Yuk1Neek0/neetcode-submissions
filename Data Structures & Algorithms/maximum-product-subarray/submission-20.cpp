class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int pmax = nums[0];
        int pmin = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){

            int a = pmax * nums[i];
            int b = pmin * nums[i];

            pmax = max(nums[i],max(a,b));
            pmin = min(nums[i],min(a,b));

            res = max(pmax,res);

        }

        return res;

    }
};
