class Solution {
public:
    int findDuplicate(vector<int>& nums) {

       int slow = 0, fast = 0;
       while(true){

            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
       }
       int slow0  = 0;
       while(true){

            slow = nums[slow];
            slow0 = nums[slow0];
            if(slow == slow0) break;
       }
       return slow0;


    }
};
