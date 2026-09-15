class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0, r = s.size() - 1;

        while( l < r ){

            while((!((s[l]>= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9')) && l < r))  l ++;
            while((!((s[r]>= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9')) && r > l )) r --;

            if( tolower(s[l]) != tolower(s[r]) ) return false;

            l++;
            r--;

        }

        return true;
        
    }
};

/*
Valid Palindrome 我感觉写的是对的 但是得到答案是错的
*/
