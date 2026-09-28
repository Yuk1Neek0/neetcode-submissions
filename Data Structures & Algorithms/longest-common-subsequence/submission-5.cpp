class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        
        int i = 0, j = 0;

        for(int i = 1; i <= text1.size(); i++){

            for(int j = 1; j <= text2.size(); j++){

                if(text1[i - 1] != text2[j - 1])
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                else dp[i][j] = dp[i - 1][j - 1] +1;

            }

        }
        return dp[text1.size()][text2.size()];

    }
};
