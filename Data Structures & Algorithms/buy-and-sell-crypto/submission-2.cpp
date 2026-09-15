class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 1) return 0;
        int res = 0;

        int l = 0 , r = 1;

        while( l < r && r < prices.size()){

            if(prices[l] >= prices[r]){

                l = r;
                r++;
                continue;

            }

            if(res < prices[r] - prices[l]){

                res = prices[r] - prices[l];

            }
            r++;
        }

        return res;

    }
};
