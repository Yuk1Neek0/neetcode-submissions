class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        int l = intervals[0][0], r = intervals[0][1];

        int res = 0;
        for(int i = 1; i < intervals.size(); i++){

            if(l == intervals[i][0]){

                res ++;
                continue;

            }

            else if(r <= intervals[i][0]){
                
                l = intervals[i][0];
                r = intervals[i][1];
                continue;

            }
            else{

                if(r > intervals[i][1]){

                    l = intervals[i][0];
                    r = intervals[i][1];

                }
                res ++;

            }
        }

        return res;

    }
};
