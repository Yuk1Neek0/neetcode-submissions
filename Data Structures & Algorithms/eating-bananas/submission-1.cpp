class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        

        int l = 1 ;
        int r = piles[0];
        int res = r;
        for(int i = 1; i < piles.size() ; i++){

            if(r < piles[i]) r = piles[i];

        }
        
        while( l <= r ){

            int mid = l + (r - l) / 2;

            long long timesum = 0;
            long long time;
            for(int i = 0; i < piles.size(); i++){

                time = (piles[i] + mid - 1) / mid ;
                timesum += time;

            }

            if(timesum <= h){
                
                 res = mid;
                 r = mid - 1;

            }
            else l = mid + 1;

        }
        return res;


    }
};
