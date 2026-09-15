class Solution {
private:
public:
    int search(vector<int>& nums, int target) {
        
        return  bisearch(nums, 0 , nums.size() -1 , target);
     

    }

    int bisearch(vector<int> & nums, int l , int r , int target){

        if( l > r ) return -1 ;
        int n = (l + r) /2;
        if(nums[n] == target){
            return n;
        }

        if(target < nums[n]) return bisearch(nums, l, n - 1, target);
        else return bisearch(nums, n + 1, r, target);
    
    }

};
