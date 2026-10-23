class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;

        int res = 0;
        unordered_set<char> dict;
        while(r < s.length()){

            while(dict.contains(s[r])){

                dict.erase(s[l]);
                l ++;

            }

            dict.insert(s[r]);
            res = max(res,r - l + 1);
            r ++;

        }
        return res;
    }
};
