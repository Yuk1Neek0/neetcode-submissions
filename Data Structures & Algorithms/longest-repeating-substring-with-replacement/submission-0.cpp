class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> count;

        if(s.length() == 1) return 1;

        int res = 0;
        int l = 0 , r = 0;
        int maxf = 0;
        while(l <= r && r < s.length()){

            count[s[r]] ++;
            maxf = max(maxf , count[s[r]]);

            if(r - l + 1 - maxf > k){

                count[s[l]] --;
                l++;

            }
            res = max(res , r - l + 1);
            r++;
        }

        return res;

    }
};
