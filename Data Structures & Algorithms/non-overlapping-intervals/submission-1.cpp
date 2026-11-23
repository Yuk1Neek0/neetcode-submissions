class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int r = intervals[0][1];
        int res = 0;

        for(int i = 1; i < intervals.size(); i++){

            int ll = intervals[i][0], rr = intervals[i][1];

            if(ll < r){

                r = min(rr,r);
                res++;

            }
            else{

                r = rr;

            }

        }
        return res;
    }
};
