class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int count[26] = { 0 };
        int l = 0;

        int maxf = 0;
        int res = 0;
        for(int r = 0; r < s.length(); r++){

            count[s[r] - 'A'] ++;
            maxf = max(count[s[r] - 'A'] , maxf);

            if(r - l + 1 - maxf > k){

                count[s[l] - 'A'] --;
                l ++;

            }

            res = max(res, r - l + 1);

        }

        return res;
    }
};