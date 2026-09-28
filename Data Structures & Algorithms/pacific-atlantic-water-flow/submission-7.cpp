class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> pmap(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>> amap(heights.size(), vector<int>(heights[0].size(),0));

        int height = heights.size(), width = heights[0].size();

        for(int i = 0; i < width; i ++){

            dfs(heights,pmap,0,i,0);
            dfs(heights,amap,height-1,i,0);

        }
        for(int i = 0; i < height; i ++){

            dfs(heights,pmap,i,0,0);
            dfs(heights,amap,i,width - 1,0);

        }

        vector<vector<int>> res;
        for(int i = 0; i < height; i ++){

            for(int j = 0; j < width; j ++){

                if(pmap[i][j] && amap[i][j]) res.push_back({i,j});
            }

        }
        return res;


    }
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& m, int x, int y, int prev){

        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()) return;
        if(heights[x][y] < prev) return;
        if(m[x][y] == 1) return;

        m[x][y] = 1;
        
        dfs(heights,m,x + 1,y,heights[x][y]);
        dfs(heights,m,x - 1,y,heights[x][y]);
        dfs(heights,m,x,y + 1,heights[x][y]);
        dfs(heights,m,x,y - 1,heights[x][y]);

    }


};
