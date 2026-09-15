class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[10][10] = {0};
        int column[10][10] = {0};
        int boxes[10][10] = {0};

        for(int i = 0 ; i < 9 ; i++){
            for(int j =0; j < 9; j++){
                
                int num = board[i][j] - '0';

                if( board[i][j] == '.') continue;
                if(row[i][num]||column[j][num]) return false;

                int inbox;
                if(i >= 0 && i <= 2){
                    
                    if( j >=0 && j <=2) inbox = 1;
                    else if( j >=3 && j <=5) inbox = 2;
                    else if( j >=6 && j <=8) inbox = 3;

                }
                else if(i >= 3 && i <= 5){
                    
                    if( j >=0 && j <=2) inbox = 4;
                    else if( j >=3 && j <=5) inbox = 5;
                    else if( j >=6 && j <=8) inbox = 6;

                }
                else if(i >= 6 && i <= 8){
                    
                    if( j >=0 && j <=2) inbox = 7;
                    else if( j >=3 && j <=5) inbox = 8;
                    else if( j >=6 && j <=8) inbox = 9;

                }

                if(boxes[inbox][num]) return false;

                row[i][num] = 1;
                column[j][num] = 1;
                boxes[inbox][num] =1;

            }

        }

        return true;
        
    }
};
