class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = piles[0];
        for(int i = 1; i < piles.size(); i ++){

            r = max(r,piles[i]);

        }
        int l = 1;
        while(l < r){

            int mid = (l + r) / 2;
            if(is_finish(piles,h,mid)) r = mid;
            else l = mid + 1;
            
        }
        return r;
    }
    bool is_finish(vector<int> & piles, int h, int speed){

        int totalh = 0;
        for(int n : piles){

            totalh += n / speed;
            if(n % speed) totalh ++;

        }
        if(totalh > h) return false;
        return true;
    }
};
