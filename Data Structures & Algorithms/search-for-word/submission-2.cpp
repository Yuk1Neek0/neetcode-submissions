class Solution {
public:
    int x[5] ={-1,0,1,0};
    int y[5] ={0,-1,0,1};
    vector<char> subres;

    int mark[6][6] = {0};
    bool res = false;
    int xbound,ybound;
    bool exist(vector<vector<char>>& board, string word) {
        
        xbound = board.size();
        ybound = board[0].size();

        for(int i = 0; i < xbound; i++){

            for(int j = 0; j < ybound; j++){

                backtracking(0,i,j,board,word);

            }

        }
        return res;

    }
    void backtracking(int n, int posx, int posy,vector<vector<char>>& board, string word){

        if(n == word.size()){

            res = true;
            return;

        }
        if(posx < 0 || posx >= xbound || posy < 0 || posy >= ybound ) return;
        char ch = board[posx][posy];
        if(ch != word[n] || mark[posx][posy] != 0) return;
        subres.push_back(ch);
        mark[posx][posy] = 1;
        for(int i = 0; i < 4; i++){

            int xx = posx + x[i];
            int yy = posy + y[i];

            
            backtracking(n + 1, xx, yy,board,word);

        }
        mark[posx][posy] = 0;
        subres.pop_back();
    }
};
