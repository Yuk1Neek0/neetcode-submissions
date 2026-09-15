class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxprofit = 0;
        int minbuy;

        minbuy = prices[0];
        if(prices.size() == 1) return 0;

        for(int i = 1; i < prices.size(); i++){

            if(prices[i] < minbuy){

                minbuy = prices[i];
                continue;
            }

            if(maxprofit < prices[i] - minbuy) maxprofit = prices[i] - minbuy;

        }

        return maxprofit; 
    }

};
