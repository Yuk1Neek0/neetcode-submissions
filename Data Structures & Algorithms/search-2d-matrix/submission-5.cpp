class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if ( target < matrix[0][0] || target > matrix[matrix.size()- 1][matrix[0].size() - 1]) return false;

        int l = 0, r = matrix.size() - 1 ;
        int x = 0;

        while ( l <= r ){

            int n = (l + r ) / 2;

            if(matrix[n][0] <= target && matrix[n][matrix[n].size() - 1] >= target){

                x = n;
                break;

            }

            if( target < matrix[n][0] ) r = n - 1;
            else l = n + 1;

        }

        l = 0, r = matrix[x].size() - 1;

        while( l <= r ){

            int n = ( l + r ) / 2;

            if( target == matrix[x][n] ) return true;

            if( target < matrix[x][n]) r = n - 1;
            else l = n + 1;

        }
        
        return false;

    }

};
