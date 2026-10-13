class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> contain;
        for(int n : nums) contain.insert(n);
        int res = 0;
        for(auto const& n : contain){

            if(contain.contains(n - 1)) continue;

            int num = n;
            int l = 0;
            while(contain.contains(num)){

                l ++;
                num = num + 1;

            }
            res = max(res,l);

        }

        return res;

    }
};
