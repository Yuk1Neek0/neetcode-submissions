class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int p1 = 0;
        int p2 = numbers.size() - 1;

        while( p1 < p2 ){

            while( p1 < p2 && numbers[p1] + numbers[p2] > target ) p2 --;

            if(numbers[p1] + numbers[p2] == target) return {p1 + 1,p2 + 1};

            while(p1 < p2 && numbers[p1] + numbers[p2] < target) p1 ++;

            if(numbers[p1] + numbers[p2] == target) return {p1 + 1,p2 + 1};

        }

        return {1,2};
    }
};
