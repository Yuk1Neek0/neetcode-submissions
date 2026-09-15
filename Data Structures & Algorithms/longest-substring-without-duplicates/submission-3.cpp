class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> sub;
        if(s.length() == 0) return 0;

        int l = 0, r = 1;
        int res = 1;
        sub.insert(s[0]);

        while(l <= r){

            if( r >= s.length() ) break;

            if(sub.count(s[r]) > 0){
                
                sub.erase(s[l]);
                l ++;

            }else{

                sub.insert(s[r]);
                res=max(res, r - l + 1);
                r++;

            }
            

        }
        
        return res;
    }
};
