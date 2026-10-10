class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(edges.size() != n - 1) return false;

        vector<int> united_map(n,0);
        for(int i = 0; i < n; i ++) united_map[i] = i;

        for(auto const &edge: edges){

            int a = edge[0];
            int b = edge[1];

            while(united_map[a] != a) a = united_map[a];
            while(united_map[b] != b) b = united_map[b];

            if(a == b) return false;

            united_map[a] = b;

        }

        return true;

    }
};
