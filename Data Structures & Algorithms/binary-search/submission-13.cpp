class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while(l <= r && l >= 0 && r < nums.size()){

            int mid = (0.5 * l + 0.5 * r);

            if(nums[mid] == target) return mid;

            if(nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;

        }

        return -1;

    }
};
