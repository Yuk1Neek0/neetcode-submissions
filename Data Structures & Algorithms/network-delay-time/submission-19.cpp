class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> delay(n + 1);
        vector<int> best(n + 1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;
        for(auto const & time : times) delay[time[0]].push_back({time[1],time[2]});
        best[k] = 0;
        que.push({0,k});

        while(!que.empty()){

            int t = que.top().first;
            int v = que.top().second;
            que.pop();

            for(auto const &route : delay[v]){

                int rv = route.first;
                int rt = route.second;

                if(t + rt < best[rv]){

                    que.push({rt + t, rv});
                    best[rv] = rt + t;

                }

            }

        }

        int res = 0;
        for(int i = 1; i <= n; i ++){
            
            int n = best[i];
            if(n == INT_MAX) return -1;
            res = max(res,n);

        }
        return res;
    }
};
/*
Network Delay Time AC 15min time:O(n*v) space:O(n+v)
思路：因为是最小栈，所以最先到达的一定是最快的方案，所以到达一个节点后，后面再到达该节点不会有这次快，理论上可以直接skip
*/