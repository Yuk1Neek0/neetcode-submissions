class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int best = nums[0], curmin = nums[0], curmax = nums[0];

        for(int i = 1; i < nums.size(); i++){

            int x = nums[i];
            int a = curmax * x;
            int b = curmin * x;

            int newmax = max(x,max(a,b));
            int newmin = min(x,min(a,b));

            curmax = newmax;
            curmin = newmin;
            best = max(newmax,best);

        }
        return best;
        
    }
};
