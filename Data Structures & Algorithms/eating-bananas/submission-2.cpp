class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1, r = *max_element(piles.begin(),piles.end());

        while(l < r){

            int mid = l + (r - l) / 2;
            if(is_enough(piles,h,mid)) r = mid;
            else l = mid + 1;

        }

        return l;

    }

    bool is_enough(vector<int>& piles,int h,int mid){

        int sum = 0;
        for(int n : piles){

            sum += (n + mid - 1)/ mid;

        }

        if(sum > h) return false;
        else return true;

    }
};
