class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> delay(n + 1);
        for(auto const &time : times) delay[time[0]].push_back({time[2],time[1]});

        vector<int> best(n + 1,INT_MAX);
        best[k] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;
        que.push({0,k});

        while(!que.empty()){

            int t = que.top().first;
            int u = que.top().second;

            que.pop();
            if(best[u] < t) continue; 
            for(auto const& edge : delay[u]){

                int ti = edge.first;
                int vi = edge.second;

               if(ti + t >= best[vi]) continue;

                que.push({ti + t, vi});
                best[vi] = ti + t;

            }

        }
        int res = 0;
        for(int i = 1; i <= n; i ++){
        
            if(best[i] == INT_MAX) return -1;
            res = max(res,best[i]);

        }
        return res;
 
    }
};
