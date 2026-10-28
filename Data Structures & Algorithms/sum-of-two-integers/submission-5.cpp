class Solution {
public:
    int getSum(int a, int b) {
        int bit = 0;

        while(b != 0){

            bit = (a & b) << 1;
            a = a ^ b;
            b = bit;

        }
        return a;
    }
};
