class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        unordered_map<int,int> minnum;

        for(int i = 0 ; i < nums.size(); i++){

            int maxfreq = 0;
            for(int j = -1000; j < nums[i]; j++){

                if(minnum.contains(j)){

                    if(maxfreq < minnum[j]) maxfreq = minnum[j];

                }

            }
            minnum[nums[i]] = maxfreq + 1;

        }
        int res = 0;
        for(int i = -1000; i <= 1000; i++){

            if(minnum.contains(i)){

                if(res < minnum[i]) res = minnum[i];

            }

        }
        return res;


    }
};
