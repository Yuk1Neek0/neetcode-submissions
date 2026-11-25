class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        int l ,r;
        int i = 0;
        vector<vector<int>> res;
        while(i < intervals.size() && newInterval[0] > intervals[i][1]){

            res.push_back(intervals[i]);
            i ++;
            
        }
        l = newInterval[0], r = newInterval[1];
        while(i < intervals.size()){

            if(intervals[i][0] <= r){

                l = min(l,intervals[i][0]);
                r = max(r,intervals[i][1]);

            }
            else{

                res.push_back({l,r});
                r = intervals[i][1];
                l = intervals[i][0];

            }
            i++;

        }
        res.push_back({l,r});
        
        return res;
    }
};
