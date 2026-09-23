class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.length() + 1,0);
        dp[0] = 1;

        for(int i = 0 ; i < s.length(); i++){

            for(string word : wordDict){

                if (word.length() > i + 1) continue;
                bool flag = true;
                for(int j = 0; j <word.length(); j++){

                    if(word[word.length() - 1 - j] != s[i - j]){

                        flag = false;
                        break;

                    }

                }
                if(flag) dp[i + 1] = dp[i + 1] || dp[i + 1 - word.length()];
 
            }

        }

        return dp[s.length()];


    }
};
