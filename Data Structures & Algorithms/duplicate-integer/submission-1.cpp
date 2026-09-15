class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            //sort
            if(nums.size()==0) return false;
            for(int i = nums.size()-1;i>=0;i--){
                 for(int j=0;j<i;j++){
                    if (nums[j] > nums[j+1]){
                        int temp=nums[j];
                        nums[j]=nums[j+1];
                        nums[j+1]=temp;
                    }
                 }
            }

            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]) return true;
            }

            return false;

    }
};