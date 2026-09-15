class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 1) return 0;

        int l = 0, r = l + 1;
        int res = 0;

        while( l < r && r < prices.size()){

            int profit = prices[r] - prices[l];

            if(profit <= 0){

                l = r;
                r ++;
                continue;

            }
            if(profit > res) res = profit;

            r++;


        }

        return res;

    }
};
/*
   Best Time to Buy and Sell Stock 12min AC
   这道题有个地方卡住了：while( l < r && r < prices.size()) 这里的条件一开始写的是while( l < r && l < prices.size()) 导致了溢出，过不了.
*/
