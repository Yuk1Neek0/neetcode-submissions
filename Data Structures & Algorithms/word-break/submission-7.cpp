class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.length() + 1,0);
        dp[0] = 1;

        for(int i = 1; i <= s.length(); i ++){

            for(string substr : wordDict){

                if(substr.length() > i) continue;

                bool flag = true;
                for(int j = 0; j < substr.length(); j++) if(substr[substr.length() - 1 - j] != s[i - j - 1]) flag = false;

                if(flag) dp[i] = dp[i - substr.length()] || dp[i];

            }

        }

        return dp[s.length()];

    }
};
