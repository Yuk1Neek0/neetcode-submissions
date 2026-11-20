class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i ++){

            for(int j = 0; j < board[0].size(); j ++){

                if(board[i][j] == word[0]){
                bool is_find = false;
                    dfs(board,word,0,i,j,is_find);
                    if(is_find) return true;

                }

            }

        }
        return false;
    }
    void dfs(vector<vector<char>>& board, string &word, int n, int x, int y, bool &is_find){

        if(n >= word.size()){

            is_find = true;
            return;

        }
        if(is_find || x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        
        if(board[x][y] == '*' || word[n] != board[x][y]) return;
        char c = board[x][y];
        board[x][y] = '*';
        dfs(board,word,n + 1,x + 1,y,is_find);
        dfs(board,word,n + 1,x,y + 1,is_find);
        dfs(board,word,n + 1,x - 1,y,is_find);
        dfs(board,word,n + 1,x,y - 1,is_find);
        board[x][y] = c;
    }
};
