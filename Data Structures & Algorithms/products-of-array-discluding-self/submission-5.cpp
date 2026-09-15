class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int suff[505];
        int pref[505];

        suff[nums.size() - 1 ] = 1;
        pref[0] = 1;

        for(int i = 1; i < nums.size(); i++){

            pref[i] = pref[i-1] * nums[i-1];

        }

        for(int i = nums.size() - 2; i >= 0; i--){

            suff[i] = suff[i + 1] * nums[i + 1];

        }
        vector<int> res(nums.size(),0);
        for(int i = 0; i < nums.size(); i++ ){

            res[i] = suff[i] * pref[i];

        }

        return res;

    }
};
