class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int pre = 0;
        int cur = 1;

        vector<int> res;
        while( cur < numbers.size()){
 
            while( numbers[pre] + numbers[cur] < target ) cur++;

            if(numbers[pre] + numbers[cur] == target){
                res = {pre+1, cur+1};
                return res;
            }

            pre ++;
            cur = pre + 1;
        }
        
        return res;
    }
};
