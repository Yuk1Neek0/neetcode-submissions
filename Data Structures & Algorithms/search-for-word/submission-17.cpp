class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool res = false;
        vector<char> substring;

        vector<vector<int>> direc = {{0,-1},{-1,0},{1,0},{0,1}};
        vector<vector<int>> been (board.size(),vector<int>(board[0].size(),0));

        for(int i = 0; i < board.size(); i++){

            for(int j = 0; j < board[0].size(); j++){

                if(board[i][j] == word[0]) backtracking(board,word,res,substring,direc,i,j,been);

            }

        }
        return res;
        
    }

    void backtracking(vector<vector<char>>& board, string word, bool &res, vector<char> &substring,vector<vector<int>> &direc, int x,int y, vector<vector<int>> &been){
        if(x>= board.size() || y >= board[0].size() || x <0 || y < 0) return;
        if(been[x][y]) return;
        substring.push_back(board[x][y]);
        been[x][y] = 1;
        if( substring.size() > word.length() || substring[substring.size() - 1] != word[substring.size() - 1] || res){

            substring.pop_back();
            been[x][y] = 0;
            return;
            
        } 

        if(substring.size() == word.length()){

            res = true;
            return;

        }

        for(int i = 0; i < 4; i ++) backtracking(board,word,res,substring,direc,x+direc[i][0],y+direc[i][1],been);
         substring.pop_back();
            been[x][y] = 0;
    }
};
