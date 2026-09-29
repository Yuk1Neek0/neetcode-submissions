class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> in_queue;
        for(int i = 0; i < grid.size(); i ++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 2) in_queue.push({i,j});
        
        int res = 0;
        while(!in_queue.empty()){

            int size = in_queue.size();
            for(int i = 0; i < size; i++){

                int x = in_queue.front().first;
                int y = in_queue.front().second;

                in_queue.pop();
                spread(grid,x + 1,y,in_queue);
                spread(grid,x - 1,y,in_queue);
                spread(grid,x,y + 1,in_queue);
                spread(grid,x,y - 1,in_queue);

            }

            if(!in_queue.empty()) res ++;

        }

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) return -1;
        return res;

    }

    void spread(vector<vector<int>>& grid,int x,int y,queue<pair<int,int>> &in_queue){

        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;

        if(grid[x][y] != 1) return;

        grid[x][y] = 2;
        in_queue.push({x,y});

    }

};
