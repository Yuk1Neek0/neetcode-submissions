class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<vector<int>> record(edges.size() + 1);

        for(auto const& edge : edges){

            int a = edge[0], b = edge[1];
            vector<int> visited(edges.size() + 1,0);

            if(traverse(record,visited,a,b)) return{a,b};
            record[a].push_back(b);
            record[b].push_back(a);

        }
        return {};
    }
    bool traverse(vector<vector<int>> &record, vector<int> &visited,int a, int b){

        if(visited[a]) return false;
        if(a == b) return true;

        bool is_loop = false;
        visited[a] = 1;
        for(int next : record[a]){

            is_loop = is_loop || traverse(record,visited,next,b);

        }

        return is_loop;

    }
};
