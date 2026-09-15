class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        if(s.length() == 1) return 1;

        for(int i = 0; i < s.length(); i++){
        
            int l = i, r = i;
            while(l >= 0 && r < s.length()){
                
                string ss = s.substr(l , r - l + 1);
                if(s[l] == s[r]) res++;
                else break;
                l--;
                r++;
            }

            l = i , r = i + 1;
             while(l >= 0 && r < s.length()){
                
                string ss = s.substr(l , r - l + 1);
                if(s[l] == s[r]) res++;
                else break;
                l--;
                r++;
            }

        }

        return res;
    }
};
