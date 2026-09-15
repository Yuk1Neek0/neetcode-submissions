class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> forward(nums.size(),1);
        vector<int> back(nums.size(),1);

        for(int i = 1; i < nums.size(); i++){

            forward[i] = forward[i - 1] * nums[i - 1];

        }

        for(int i = nums.size() - 2; i >= 0 ; i--){

            back[i] = back[i + 1] * nums[i + 1];

        }

        vector<int> res;

        for(int i = 0; i < nums.size() ; i++){

            res.push_back(forward[i] * back[i]);

        }

        return res;

    }
};
