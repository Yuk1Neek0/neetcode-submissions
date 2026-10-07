class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int res = n;

        vector<int> roots(n,0);

        for(int i = 0; i < n; i ++) roots[i] = i;

        for(auto const & edge : edges){

            if(res == 1) break;

            int a = edge[0];
            int b = edge[1];

            while(roots[a] != a) a = roots[a];
            while(roots[b] != b) b = roots[b];

            if(a != b) res --;

            roots[a] = b;

        }

        return res;

    }
};
