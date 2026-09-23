class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int buttom = matrix.size() - 1, top = 0;

        int xstart = 105;

        while(top <= buttom){

            int mid = top + (buttom - top) / 2;

            if( target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1]){
                xstart = mid;
                break;
            }
            if(target < matrix[mid][0]) buttom = mid - 1;
            else top = mid + 1;

        }
        if(xstart == 105) return false;

        int l = 0, r = matrix[0].size();

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(matrix[xstart][mid] == target) return true;
            if(target < matrix[xstart][mid]) r = mid - 1;
            else l = mid + 1;

        }

        return false;

    }
};
