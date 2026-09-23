class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        queue<pair<int,int>> que;

        for(int i = 0; i < grid.size(); i++){

            for(int j = 0; j < grid[0].size(); j ++){

                if(grid[i][j] == 2) que.push({i,j});

            }

        }

        int res = 0;
        while(!que.empty()){

            int size = que.size();

            for(int i = 0; i < size; i ++){

                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                spread(grid,que,x + 1,y);
                spread(grid,que,x - 1,y);
                spread(grid,que,x,y + 1);
                spread(grid,que,x,y - 1);

            }
           if(!que.empty()) res ++;

        }

        for(auto const & i : grid)
            for(int n : i) if(n == 1) return -1;
        return res;


    }
    void spread(vector<vector<int>>& grid,queue<pair<int,int>> &que, int x, int y){

        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;

        if(grid[x][y] == 2 || grid[x][y] == 0) return;

        grid[x][y] = 2;
        que.push({x,y});

    }
};
