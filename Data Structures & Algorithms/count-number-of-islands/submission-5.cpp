class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0;

        for(int i = 0; i < grid.size(); i++){

            for(int j = 0; j < grid[0].size(); j++){

                if(grid[i][j] == '1'){

                    res++;
                    sink(grid, i, j);

                }
                
            }

        }
        return res;

    }
    void sink(vector<vector<char>> & grid, int i, int j){

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;

        if(grid[i][j] == '0') return;
        grid[i][j] = '0';

        int dirc[4][4] = {{1,0},{0,-1},{-1,0},{0,1}};

        for(int k = 0; k < 4; k++){

            sink(grid,i + dirc[k][0],j + dirc[k][1]);

        }

    }
};
