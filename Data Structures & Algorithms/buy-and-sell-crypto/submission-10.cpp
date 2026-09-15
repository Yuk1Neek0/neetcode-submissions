class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 1) return 0;

        int l = 0, r = l + 1;
        int res = 0;

        while( l < r && r < prices.size()){

            int profit = prices[r] - prices[l];

            if(profit <= 0){

                l ++;
                r = l + 1;
                continue;

            }
            if(profit > res) res = profit;

            r++;


        }

        return res;

    }
};
