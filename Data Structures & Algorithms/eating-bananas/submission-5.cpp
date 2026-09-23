class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxt = 0 , mint = 1;
        for(int i = 0; i < piles.size(); i++) maxt = max(maxt,piles[i]);

        while(maxt > mint){

            int midt = mint + (maxt - mint)/2;

            if(time_enough(piles,h,midt)) maxt = midt;
            else mint = midt + 1;

        }

        return maxt;

    }
    bool time_enough(vector<int> &piles, int h, int t){

        int sumt = 0;
        for(int n : piles){

            sumt += (n + t - 1) / t;
            if(sumt > h) return false;

        }
        return true;

    }
};
