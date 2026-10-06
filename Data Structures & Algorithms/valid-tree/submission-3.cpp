class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(n - 1!= edges.size()) return false;

        vector<int> validmap(n,0);
        for(int i = 0; i < n; i ++) validmap[i] = i;

        for(auto const &edge : edges){

            int a = edge[0];
            int b = edge[1];

            while(validmap[a] != a) a = validmap[a];
            while(validmap[b] != b) b = validmap[b];
            if(a == b) return false;

            validmap[a] = b;

        }

        return true;

    }
};
