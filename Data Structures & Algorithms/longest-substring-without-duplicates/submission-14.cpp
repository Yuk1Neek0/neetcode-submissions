class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0) return 0;
        unordered_map<char,int> appear;
        appear[s[0]] = 0;
        int l = 0, r = 1;

        int res = 1;
        while( l < r && r < s.length() && l < s.length()){

            if(appear.contains(s[r])){

                for(int i = l; i < appear[s[r]]; i++){

                    appear.erase(s[i]);

                }
                l = appear[s[r]] + 1;
                appear[s[r]] = r;
                r++;
                continue;

            }

            if(r - l + 1 > res) res = r - l + 1;
            appear[s[r]] = r;
            r ++;

        }

        return res;

    }
};
/*
Longest Substring Without Repeating Characters 这题没思路,知道要用滑动窗口，但是不知道怎么shrink
*/