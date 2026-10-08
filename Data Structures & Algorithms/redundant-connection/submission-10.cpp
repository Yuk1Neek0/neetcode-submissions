class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> union_map(edges.size() + 1,0);
        for(int i = 1;i < union_map.size(); i ++) union_map[i] = i;

        for(auto const &edge : edges){

            int a = edge[0];
            int b = edge[1];

            while(union_map[a] != a) a = union_map[a];
            while(union_map[b] != b) b = union_map[b];

            if(a == b) return {edge[0],edge[1]};
            else union_map[a] = b;

        }

        return {};

    }
};
