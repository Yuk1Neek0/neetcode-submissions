class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> visitedP(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>> visitedA(heights.size(), vector<int>(heights[0].size(),0));


        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, 0,     0, visitedP);      
            dfs(heights, i, heights[0].size() - 1, 0, visitedA);      
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, 0,     j, 0, visitedP);    
            dfs(heights, heights.size() - 1, j, 0, visitedA);      
        }

        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); i++){

            for(int j = 0; j < heights[0].size(); j++){

                if(visitedA[i][j] && visitedP[i][j]) res.push_back({i,j});

            }

        }
        return res;

    }

    void dfs(vector<vector<int>>& heights, int x, int y, int prev, vector<vector<int>>& visited){

        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()) return;
        if(visited[x][y]) return;
        if(heights[x][y] < prev) return;

        visited[x][y] = 1;

        dfs(heights,x + 1, y, heights[x][y],visited);
        dfs(heights,x - 1, y, heights[x][y],visited);
        dfs(heights,x, y + 1, heights[x][y],visited);
        dfs(heights,x, y - 1, heights[x][y],visited);
        
        
    }
};
