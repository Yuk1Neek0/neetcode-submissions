class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i ++){

            for(int j = 0; j < board[0].size(); j++){

                if(board[i][j] == word[0]){

                    bool is_find = false;
                    dfs(board,word,is_find,i,j,0);
                    if(is_find) return true;

                }

            }

        }
        return false;

    }
    void dfs(vector<vector<char>>& board, string &word, bool& is_find, int x, int y, int n){

        if(is_find || n >= word.length()){

            is_find = true;
            return;

        }

        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(board[x][y] == '*' || board[x][y] != word[n]) return;

        char c = board[x][y];
        board[x][y] = '*';
        dfs(board,word,is_find,x + 1,y,n + 1);
        dfs(board,word,is_find,x,y + 1,n + 1);
        dfs(board,word,is_find,x - 1,y,n + 1);
        dfs(board,word,is_find,x,y - 1,n + 1);
        board[x][y] = c;

    }
};
