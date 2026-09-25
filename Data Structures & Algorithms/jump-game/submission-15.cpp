class Solution {
public:
    bool canJump(vector<int>& nums) {

        int pos = 0;
        while(pos < nums.size()){

            if(pos >= nums.size() - 1 || pos + nums[pos] >= nums.size() - 1 ) return true;
            if(nums[pos] == 0) return false;
            int bestreach = 0, best = pos;

            for(int i = 1; i <= nums[pos]; i ++){

                if(bestreach < nums[pos + i] + pos + i){

                    bestreach = nums[pos + i] + pos + i;
                    best = pos + i;

                }

            }
            pos = best;
            
        }
        return true;

    }
};
