class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dict;
        int res = 0;

        int l = 0, r = 0;
        while(r < s.length()){

            if(!dict.contains(s[r])) {

                dict.insert(s[r]);
                res = max(res, r - l + 1);
                r ++;
            }
            else{

                while(l <= r && dict.contains(s[r])){

                    dict.erase(s[l]);
                    l ++;
                }

            }

        }
        return res;
    }   
};
