class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool find = false;
        vector<vector<int>> been(board.size(), vector<int>(board[0].size(),0));
        for(int i = 0; i < board.size(); i++){

            for(int j = 0; j < board[0].size(); j++){
                
                if(board[i][j] == word[0])
                backtracking(board,word,0,find,i,j,been);

            }

        }

        return find;

    }

    void backtracking(vector<vector<char>>& board, string word, int n, bool &find, int x,int y, vector<vector<int>> &been){

        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || find) return;

        if(been[x][y]) return;

        if(board[x][y] != word[n]) return;

        been[x][y] = true;
        n++;

        if(n == word.length()){

            find = true;
            return;

        }

        backtracking(board,word,n,find,x + 1,y,been);
        backtracking(board,word,n,find,x,y + 1,been);
        backtracking(board,word,n,find,x - 1,y,been);
        backtracking(board,word,n,find,x,y - 1,been);
        been[x][y] = false;
        n --;

    }
};
