class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0, r = nums.size() - 1;

        if (r == 0) return nums[0];
        int res = nums[0];

        while( l <= r ){

            int mid = (l + r) / 2;
            if(nums[l] < nums[r]) return nums[l];
            if( mid == 0 ){

                if(nums[mid] < nums[mid + 1] && nums[mid] < nums[nums.size() - 1]) return nums[mid];

            }
            else if(mid == nums.size() - 1){

                if(nums[mid] < nums[mid - 1] && nums[mid] < nums[0]) return nums[mid];

            }
            else if(nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) return nums[mid];

            if(nums[mid] >= nums[l]) l = mid + 1;
            else r = mid - 1;

        }
        
        return res;

    }
};
