class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        if(s.length() == 0) return res;

        int l = 0, r = 0;
        unordered_set<char> unoset;

        while( l <= r && r < s.length() ){

            if(unoset.count(s[r])){

                l ++;
                r = l;
                unoset.clear();
                continue;

            }

            unoset.insert(s[r]);
            r++;

            if(r - l > res) res = r - l;

        }

        return res;
    }
};
