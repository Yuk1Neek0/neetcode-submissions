class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        vector<int> subres = intervals[0];
        vector<vector<int>> res;

        for(int i = 1; i < intervals.size(); i++){

            if(intervals[i][0] <= subres[1]){

                if(intervals[i][1] > subres[1]) subres[1] = intervals[i][1];

            }
            else{

            res.push_back(subres);
            subres = intervals[i];

            }
            

        }

        res.push_back(subres);
        return res;

    }
};
