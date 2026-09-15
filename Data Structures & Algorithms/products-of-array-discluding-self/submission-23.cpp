class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> product(nums.size(),0);
        product[0] = 1;

        for(int i = 1; i < nums.size(); i ++){

            product[i] = product[i-1] * nums[i - 1];

        }

        int subproduct = 1;
        for(int i = nums.size() - 1; i >= 0 ; i--){

            product[i] *= subproduct;

            subproduct *= nums[i];

        }

        // vector<int> res;
        // // for(auto& n : product){

        // //     res.push_back(n);

        // // }
        // for(int i = 0; i < product.length(); i ++){

        //     res[i] = product[i];

        // }
        // return res;
        return product;
    }
};
