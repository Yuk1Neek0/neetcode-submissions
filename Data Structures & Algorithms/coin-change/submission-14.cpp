class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp (amount+5,10005);
        dp[0] = 0;

        for(int i = 1; i <= amount; i ++){

            for(int j = 0; j < coins.size(); j++){

                if(i - coins[j] >=0) dp[i] = min(dp[i] , dp[i - coins[j]] + 1);

            }
        
        }

        if(dp[amount] != 10005) return dp[amount];
        else return -1;

    }
};
