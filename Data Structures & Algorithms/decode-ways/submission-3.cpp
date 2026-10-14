class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); i ++){

            for(int j = 1; j <= 26; j ++){

                if(j <= 9) {

                    if(j == s[i - 1] - '0') dp[i] += dp[i - 1];

                }
                else{

                    if(i < 2) continue;
                    
                    int a = j % 10;
                    int b = j / 10;

                    if(s[i - 1] - '0' == a && s[i - 2] - '0' == b) dp[i] += dp[i - 2];
                    
                }

            }

        }

        return dp[s.length()];
    }
};
