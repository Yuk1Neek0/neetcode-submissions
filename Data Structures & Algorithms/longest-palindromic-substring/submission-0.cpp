class Solution {
public:
    string longestPalindrome(string s) {
        
        int reslen = 0, resindex;

        for(int i = 0; i < s.length(); i++){

            int l = i, r = i;
            while(l >=0 && r < s.length() && s[l] == s[r]){
                
                int len = r - l + 1;
                if(reslen < len){

                    reslen = len;
                    resindex = l;

                }
                l--;
                r++;

            }
            l = i;
            r = i+1;
            while(l >=0 && r < s.length() && s[l] == s[r]){

                int len = r - l + 1;
                if(reslen < len){

                    reslen = len;
                    resindex = l;

                }
                l--;
                r++;

            }
            
        }
        return s.substr(resindex,reslen);

    }
};
