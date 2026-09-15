class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0;
        int mostfreq = 0;
        int freq[26] = {0};
        int res = 0;
        for(int r = 0; r < s.length(); r++){

            freq[s[r] - 'A'] ++;
            mostfreq = max(mostfreq,freq[s[r] - 'A']);

            if(r - l + 1 - mostfreq > k){

                freq[s[l] - 'A'] --;
                mostfreq = 0;
                for(int n : freq) if(mostfreq < n) mostfreq = n;
                l ++;

            }

            if(res < r - l + 1) res = r - l + 1; 

        }
        return res;
        

    }
};
