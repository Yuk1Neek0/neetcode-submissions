class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int flag = 1;

        int i = 0, j = 0;
        while(res.size() < matrix.size() * matrix[0].size()){

            if(flag == 1){
                
                if(j == matrix[0].size() || matrix[i][j] == 105){
                    
                    j --;
                    i ++;
                    flag = 2;
                    continue;

                }
                res.push_back(matrix[i][j]);
                matrix[i][j] = 105;
                j ++;
            }
            if(flag == 2){

                if(i == matrix.size() || matrix[i][j] == 105){

                    i --;
                    j --;
                    flag = 3;
                    continue;

                }
                res.push_back(matrix[i][j]);
                matrix[i][j] = 105;
                i ++;

            }
            if(flag == 3){

                if(j == -1 || matrix[i][j] == 105){
                    
                    i--;
                    j++;
                    flag = 4;
                    continue;

                }
                res.push_back(matrix[i][j]);
                matrix[i][j] = 105;
                j --;

            }
            if(flag == 4){

                if(i == -1|| matrix[i][j] == 105){

                    j++;
                    i++;
                    flag = 1;
                    continue;

                }
                res.push_back(matrix[i][j]);
                matrix[i][j] = 105;
                i --;

            }

        }
        return res;
    }
};
