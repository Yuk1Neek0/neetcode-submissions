class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> seen;

        int l = 0;
        int res = 0;
        for(int r = 0; r < s.length(); r ++){

            if(seen.contains(s[r])){

                while(s[l] != s[r]){
                    
                    seen.erase(s[l]);
                    l++;

                }
                l++;

            }

            seen.insert(s[r]);
            if(res < r - l + 1) res = r - l + 1;

        }
        return res;

    }
};
