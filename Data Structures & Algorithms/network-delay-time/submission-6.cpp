class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto const& time : times) adj[time[0]].push_back({time[1],time[2]});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});

        while(!pq.empty()){

            int t = pq.top().first;
            int u = pq.top().second;

            pq.pop();
            if(t > dist[u])    continue;

            for(auto const& edge : adj[u]){

                if(t + edge.second < dist[edge.first]){

                    dist[edge.first] = t + edge.second;
                    pq.push({t + edge.second,edge.first});

                }

            }

        }

        int res = 0;
        for(int i = 1; i <= n ; i ++){

            if(dist[i] == INT_MAX) return -1;
            res = max(res,dist[i]);
 
        }
        return res;
        
    }
 
};

