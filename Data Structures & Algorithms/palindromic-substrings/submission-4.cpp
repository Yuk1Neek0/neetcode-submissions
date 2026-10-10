class Solution {
public:
    int countSubstrings(string s) {
        
        int res = 0;

        for(int i = 0; i < s.length(); i++){

            int l = i, r = i;

            while(l <= r && r < s.length() && l >= 0){

                if(s[l] != s[r]) break;
                res ++;
                l --;
                r ++;
            }

            if(i > 0){

                l = i - 1, r = i;

                while(l <= r && r < s.length() && l >= 0){

                    if(s[l] != s[r]) break;
                    res ++;
                    l --;
                    r ++;

                }
                
            }

        }

        return res;

    }
};
