class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0, r = 1;
        int Maxprofit = 0;
        if(prices.size() == 1) return 0;

        while( l < r ){
            
            if(r >= prices.size()) break;
            if( prices[l] < prices[r] ){

                int profit = prices[r] - prices[l];
                if(profit > Maxprofit) Maxprofit = profit;

            } else l = r;

            r ++;

        }
        return Maxprofit;

    }
};
