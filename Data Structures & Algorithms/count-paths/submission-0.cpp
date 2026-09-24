class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> pathmap(m,vector<int>(n,0));
        
        pathmap[0][0] = 1;
        
        for(int i = 0; i < m ; i ++){

            for(int j = 0; j < n; j ++){

                if(i == 0 && j == 0) continue;
                if(i == 0) pathmap[i][j] += pathmap[i][j - 1];
                else if(j == 0) pathmap[i][j] += pathmap[i - 1][j];
                else pathmap[i][j] = pathmap[i][j-1] + pathmap[i-1][j];

            }

        }
        
        return pathmap[m - 1][n - 1];
    }
};
