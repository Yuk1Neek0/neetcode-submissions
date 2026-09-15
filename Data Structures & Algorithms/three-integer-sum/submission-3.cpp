class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i ++){

            if( nums[i] > 0 ) break;
            int l = i + 1, r = nums.size() - 1;
            while( l < r ){

                if( nums[i] + nums[l] + nums[r] < 0 ){

                    l ++;
                    continue;
                    
                }
                else if ( nums[i] + nums[l] + nums[r] > 0 ){

                    r --;
                    continue;

                }
                else{

                    vector<int> subres;
                    subres.push_back(nums[i]);
                    subres.push_back(nums[l]);
                    subres.push_back(nums[r]);
                    res.push_back(subres);

                    l ++;
                    r --;
                    while(l < nums.size() && nums[l] == nums[l - 1]){

                        l ++;

                    }

                    while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i ++;
                }

            }
            

        }

        return res;
        
    }
};
