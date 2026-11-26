class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length() + 1,0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); i ++){

            for(int j = 0; j < wordDict.size(); j ++){
                int wordl = wordDict[j].length();
                if(i - wordl < 0) continue;
                if(dp[i - wordl] != 1) continue;
                string subs = s.substr(i - wordl,wordl);
                if(subs == wordDict[j]) dp[i] = 1;


            }
        }
        return dp[s.length()];
    }


};
