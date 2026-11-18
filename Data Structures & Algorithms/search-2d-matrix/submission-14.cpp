class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bot = matrix.size() - 1;
        int l = 0 , r = matrix[0].size();
        int startrow = -1;
        while(bot >= top){

            int mid = (bot + top) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size() - 1]){

                startrow = mid;
                break;

            }
            if(target < matrix[mid][0]) bot = mid - 1;
            else top = mid + 1;

        }
        if(startrow == -1) return false;
        while(l <= r){

            int mid = (l + r) /2;
            if(matrix[startrow][mid] == target) return true;
            if(target > matrix[startrow][mid]) l = mid + 1;
            else r = mid - 1;

        }
        return false;
    }
};
