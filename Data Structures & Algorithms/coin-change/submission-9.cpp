class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int INF = amount + 1;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INF));
        
        for(int i = 0; i < coins.size(); i++) dp[i][0] = 0;

        for(int i = 0; i < coins.size(); i++){

            for(int j = 1; j <= amount; j++){

                if(i == 0){

                    if(j - coins[i] >= 0 && dp[i][j - coins[i]] != INF)  dp[i][j] = dp[i][j - coins[i]] + 1;

                }
                else{

                    dp[i][j] =dp[i - 1][j];
                    if(j - coins[i] >= 0 && dp[i][j - coins[i]] != INF) dp[i][j] = min(dp[i - 1][j],dp[i][j - coins[i]] + 1);

                }

            }

        }
        return dp[coins.size() - 1][amount] == INF ? -1 : dp[coins.size() - 1][amount] ;

    }
};
