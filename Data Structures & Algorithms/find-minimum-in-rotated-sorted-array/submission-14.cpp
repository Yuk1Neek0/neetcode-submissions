class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0, r = nums.size() - 1;

        while( l < r ){

            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;

        }

        return nums[r];

    }
};
/*
   Find Minimum in Rotated Sorted Array 6min ac 9.3重做
   这题应该和右边比。 
*/