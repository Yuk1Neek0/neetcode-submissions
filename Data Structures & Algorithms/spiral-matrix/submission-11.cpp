class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;

        vector<int> res;
        int dirc = 1;

        while(top <= bottom && left <= right){

            if(dirc == 1){

                for(int i = left; i <= right; i ++){

                    res.push_back(matrix[top][i]);

                }
                dirc = 2;
                top ++;

            }
            else if(dirc == 2){


                for(int i = top; i <= bottom; i ++){

                    res.push_back(matrix[i][right]);

                }
                dirc = 3;
                right --;

            }
            else if(dirc == 3){

                for(int i = right; i >= left; i --) res.push_back(matrix[bottom][i]);
                dirc = 4;
                bottom --;
            }
            else if(dirc == 4){

                for(int i = bottom; i >= top; i --) res.push_back(matrix[i][left]);
                dirc = 1;
                left ++;
            }
            
        }
        return res;
    }
};
