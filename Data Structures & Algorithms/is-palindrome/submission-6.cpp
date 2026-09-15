class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.length() == 1) return true;

        int l = 0, r = s.length() - 1;

        while( l < r ){

            if(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))){

                l ++;
                continue;

            }

            if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))){

                r --;
                continue;

            }

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--; 

        }
        
        return true;
    }
};
