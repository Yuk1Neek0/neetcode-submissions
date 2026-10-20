class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        vector<int> freq(26,0);
        int res = 0;
        while(r < s.length()){

            freq[s[r] - 'A'] ++;
            r ++;
            int mfreq = 0;
            for(int i = 0; i < 26; i ++) mfreq = max(mfreq,freq[i]);
            while(r - l - mfreq > k){

                freq[s[l] - 'A'] --;
                l ++;
                for(int i = 0; i < 26; i ++) mfreq = max(mfreq,freq[i]);

            }
            res = max(res, r - l);
            
        }
        return res;
    }
};
