class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>  atlantic(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>  been(heights.size(),vector<int>(heights[0].size(),0));
        int height = heights.size();
        int width = heights[0].size();
        for(int i = 0; i < heights.size(); i ++){

            pacific[i][0] = 1;
            atlantic[i][width - 1] = 1;
        }
        for(int i = 0; i < width; i ++){

            pacific[0][i] = 1;
            atlantic[height - 1][i] = 1;

        }
        for(int i = 0; i < height; i ++){

            dfs(heights,pacific,atlantic,i,0,i,0,been);
            dfs(heights,pacific,atlantic,i,width - 1,i,width - 1,been);

        }
        for(int i = 0; i < width; i ++){

            dfs(heights,pacific,atlantic,0,i,0,i,been);
            dfs(heights,pacific,atlantic,height - 1,i,height - 1,i ,been);

        }
        vector<vector<int>> res;
        for(int i = 0; i < height; i ++){

            for(int j = 0 ; j < width; j ++){

                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});

            }

        }
        return res;

    }
    void dfs(vector<vector<int>>& heights,vector<vector<int>>  &pacific,vector<vector<int>>  &atlantic, int x, int y, int prex, int prey,vector<vector<int>> &been){

        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()) return;
        if(been[x][y]) return;
        if(heights[x][y] < heights[prex][prey]) return;
        if(pacific[prex][prey]) pacific[x][y] = 1;
        if(atlantic[prex][prey]) atlantic[x][y] = 1;

        been[x][y] = 1;
        dfs(heights,pacific,atlantic,x + 1,y,x,y,been);
        dfs(heights,pacific,atlantic,x,y + 1,x,y,been);
        dfs(heights,pacific,atlantic,x - 1,y,x,y,been);
        dfs(heights,pacific,atlantic,x,y - 1,x,y,been);
        been[x][y] = 0;

        

    }
};
