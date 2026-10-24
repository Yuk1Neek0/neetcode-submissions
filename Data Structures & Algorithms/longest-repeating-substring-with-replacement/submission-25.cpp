class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int res = 0;

        vector<int> freq(26,0);
    
        while(r < s.length()){

            freq[s[r] - 'A'] ++;
            r++;
            int maxfreq = 0;
            for(int i = 0; i < 26; i ++) maxfreq = max(maxfreq,freq[i]);

            if(r - l- maxfreq > k){

                freq[s[l] - 'A'] --;
                l ++;
                for(int i = 0; i < 26; i ++) maxfreq = max(maxfreq,freq[i]);

            }
            else{

                res = max(res,r - l);
            } 
            
        }
        return res;
    }
};
