class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> que;

        for(int i = 0; i < points.size(); i ++){
            vector<int> point = points[i];
            int dist = pow(point[0],2) + pow(point[1],2);
            if(que.size() < k) que.push({dist,i});
            
            else{

                if(dist < que.top().first){

                    que.pop();
                    que.push({dist,i});

                }

            }

        }
        vector<vector<int>> res;
        while(!que.empty()){

            res.push_back({points[que.top().second][0],points[que.top().second][1]});
            que.pop();

        }
        return res;
    }
};
