class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> kclosest;


        for(int i = 0; i < points.size(); i++ ){

            int dist = pow(points[i][0],2) + pow(points[i][1],2);

            if(kclosest.size() < k) kclosest.push({dist,i});
            else{
                
                if(kclosest.top().first > dist){
                kclosest.pop();
                kclosest.push({dist,i});

                }

            }

        } 

        vector<vector<int>> res;

        while(!kclosest.empty()){

            res.push_back({points[kclosest.top().second][0],points[kclosest.top().second][1]});
            kclosest.pop();

        }

        return res;

    }
};
