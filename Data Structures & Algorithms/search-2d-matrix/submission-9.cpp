class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int top = 0, buttom = matrix.size() - 1;
        int xstart = 105;

        while(top <= buttom){

            int mid = top + (buttom - top) / 2;

            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1]) {

                xstart = mid;
                break;

            }
            else if(target > matrix[mid][matrix[mid].size() - 1]) top = mid + 1;
            else buttom = mid - 1;

        }

        if(xstart == 105) return false;

        int l = 0, r = matrix[0].size() - 1;

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(target == matrix[xstart][mid]) return true;
            else if(target >matrix[xstart][mid]) l = mid + 1;
            else r = mid - 1;

        }

        return false;
    }
};
