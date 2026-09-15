class Solution {
public:
    bool isPalindrome(string s) {
        
        int p1 = 0 , p2 = s.length() - 1;

        while(p1 < p2){

            while(p1 < p2 && !isalpha(s[p1])) p1++;
            while(p1 < p2 && !isalpha(s[p2])) p2--;

            if(tolower(s[p1]) != tolower(s[p2])) return false;

            p1++;
            p2--;
           
        }
        
        return true;
    }

    bool isalpha (char n){

        if((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z') || (n >= '0' && n <= '9')) return true;
        else return false;

    }
};
