class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0, r = s.size() - 1;

        while( l < r ){

            while(!isalnum(s[l]) && l < r)  l ++;
            while(!isalnum(s[r]) && r > l ) r --;

            if( tolower(s[l]) != tolower(s[r]) ) return false;

            l++;
            r--;

        }

        return true;
        
    }
};

/*
Valid Palindrome 12min AC 
这题本来一直AC不了 最后发现这题忽略大小写。 浪费好多时间。 然后  isalnum这个函数不知道为什么过不了 手撕的alpha判断
*/
