class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,less<pair<int,int>>>maxheap;

        for(int i = 0; i < points.size() ; i++){

            int dist = pow(points[i][0],2) + pow(points[i][1],2);

            if(maxheap.size() < k) maxheap.push({dist,i});
            else if(dist < maxheap.top().first){

                maxheap.pop();
                maxheap.push({dist,i});

            }

        }

        vector<vector<int>> res;
        for(int i = 0; i < k; i++){

            res.push_back({points[maxheap.top().second][0],points[maxheap.top().second][1]});
            maxheap.pop();

        }
        return res;

    }
};
