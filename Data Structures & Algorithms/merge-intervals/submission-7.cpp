class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prevl = intervals[0][0], prevr = intervals[0][1];
        vector<int> subres(2,0);
        subres[0] = prevl;
        subres[1] = prevr;
        vector<vector<int>> res;
        for(int i = 1; i < intervals.size(); i ++){

            if(intervals[i][0] <= subres[1]){

                subres[1] = max(subres[1],intervals[i][1]);

            }
            else{

                res.push_back(subres);
                subres[0] = intervals[i][0];
                subres[1] = intervals[i][1];

            }

        }
        res.push_back(subres);
        return res;
    }
};
