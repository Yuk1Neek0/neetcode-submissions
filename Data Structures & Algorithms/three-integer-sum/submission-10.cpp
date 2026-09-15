class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() -2; i++ ){
            if(nums[i] >0) break;
            if( i > 0 && nums[i] == nums[i -1] ) continue;
            int l = i + 1, r = nums.size() - 1;

            while( l < r ){

                int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0) {

                res.push_back({nums[i],nums[l],nums[r]});
                l ++;
                while(l < r && nums[l] == nums[l - 1 ]  ) l ++;

            }

            if(sum > 0) r --;
            if(sum < 0) l ++;


            }

            

        }

        return res;

    }
};

/*
3Sum 这题我记得是可以固定一个数 然后把问题转换为 2Sum，但是忘记了怎么去重。
*/