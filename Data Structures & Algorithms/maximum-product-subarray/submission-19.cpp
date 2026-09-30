class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = nums[0];
        int mini = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i ++){

            int a = maxi * nums[i];
            int b = mini * nums[i];

            maxi = max(nums[i],max(a,b));
            mini = min(nums[i],min(a,b));

            res = max(maxi,res);

        }

        return res;

    }
};
