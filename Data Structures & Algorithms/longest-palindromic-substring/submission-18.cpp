class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        res.push_back(s[0]);
        for(int i = 0; i < s.length(); i ++){

            int l = i - 1, r = i + 1;
            while(r < s.length() &&  l >= 0 && s[l] == s[r]){

                if(r - l + 1 > res.length()) res = s.substr(l, r - l + 1);
                l --;
                r ++;
        
            }
            
            l = i, r = i + 1;
            while(r < s.length() &&  l >= 0 && s[l] == s[r]){

                if(r - l + 1 > res.length()) res = s.substr(l, r - l + 1);
                l --;
                r++;
                

            }
            

        }
        return res;
    }
};
