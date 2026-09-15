class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int products = 1;
        bool zero = false;
        int zeroind;
        bool multizero = false;
        for( int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(!zero){

                    zeroind = i;
                    zero = true;
                    continue;
                }
                multizero = true;
            }
            products *= nums[i];

        }

        for(int i = 0; i < nums.size(); i++){
            
            if(multizero){
                nums[i] = 0;
                continue;
            }

            if(zero){
                if(zeroind == i){
                    nums[i] = products;
                }else nums[i] = 0;
            }
            else nums[i] = products / nums[i];

            
        }

        return nums;

    }
};
