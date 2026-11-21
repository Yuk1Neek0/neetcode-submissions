class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> subres(2);
        subres[0] = intervals[0][0];
        subres[1] = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 1 ; i < intervals.size(); i ++){

            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l <= subres[1]){

                subres[1] = max(subres[1],r);
                continue;

            }
            else{

                res.push_back(subres);
                subres[0] = l;
                subres[1] = r;

            }

        }
        res.push_back(subres);
        return res;
    }
};
