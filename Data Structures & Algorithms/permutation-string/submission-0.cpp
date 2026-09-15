class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int sub[30] = {0};

        int count[30] = {0};

        int l = 0;

        for(char ch : s1){

            sub[ch - 'a']++;

        }

        int r = 0;
        while(r < s2.length()){

            count[s2[r] - 'a'] ++;

            while(count[s2[r] - 'a'] > sub[s2[r] - 'a'] && l <= r){

                count[s2[l] - 'a'] --;
                l ++;

            }

            if(r - l + 1 == s1.length()) return true;

            r++;

        }
        return false;

    }
};
