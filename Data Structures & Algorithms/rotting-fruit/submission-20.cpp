class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++){

            for(int j = 0; j < grid[0].size(); j ++){

                if(grid[i][j] == 2) rotten.push({i,j});
                if(grid[i][j] == 1) fresh ++;

            }

        }
        int res = 0;
        vector<vector<int>> dirc{{0,1},{1,0},{-1,0},{0,-1}};
        while(!rotten.empty()){

            int size = rotten.size();
            for(int i = 0 ; i < size; i ++){

                spread(grid,rotten.front().first,rotten.front().second,rotten,dirc,fresh);
                rotten.pop();

            }
            if(rotten.size() != 0) res++;

        }
        if(fresh != 0) return-1;
        return res;
    }
    void spread(vector<vector<int>>& grid, int x,int y,queue<pair<int,int>> &rotten,vector<vector<int>> &dirc,int &fresh){

        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        for(int i = 0; i < 4; i ++){

            int xx = x + dirc[i][0];
            int yy = y + dirc[i][1];
            if(xx < 0 || xx >= grid.size() || yy < 0 || yy >= grid[0].size()) continue;
            if(grid[xx][yy] != 1) continue;

            grid[xx][yy] = 2;
            fresh --;
            rotten.push({xx,yy});            

        }
    }
};
