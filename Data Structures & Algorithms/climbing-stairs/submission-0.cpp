class Solution {
public:
    int climbStairs(int n) {
        
        int dp[35] = {0};
        dp[0] = 1;
        for(int i = 1; i<=n ; i++){

            if(i >= 2){

                dp[i] = dp[i-1] + dp[i-2];

            }
            else if( i == 1){

                dp[i] = dp[i-1];

            }

        }

        return dp[n];
            }
};
