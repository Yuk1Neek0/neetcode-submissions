class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> seq;
        int res = 0;

        if(nums.size() == 0) return 0;

        for(int n : nums){

            seq.insert(n);
            
        }

        for(int n : seq){

            if(seq.contains(n - 1)) continue;

            int length = 1;

            while(seq.contains(n + length)) length ++;

            if(res < length) res = length;

        }

        return res;
        
    }
};
