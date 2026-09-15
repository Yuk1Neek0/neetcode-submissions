class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int res = 0;
        int maxcount[26] = {0};
        int l = 0, r = 0;
        while(r < s.length()){


            maxcount[s[r] - 'A'] ++;
            
            int maxf = 0;
            for(int n : maxcount){

                if(maxf < n) maxf = n;

            }
            if(r - l + 1 - maxf > k){

                maxcount[s[l] - 'A'] --;
                l ++;

                r ++;
                continue;
                
            } 

            if(res < r - l + 1) res = r - l + 1;

            r++;  
        }
        return res;

    }
};
