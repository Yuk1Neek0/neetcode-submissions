class Solution {
public:
    int getSum(int a, int b) {
        int bit = 0;

        while(a!=0){

            bit =(a & b) << 1;
            b = a ^ b ;
            a = bit;
            

        }
        return a ^ b;
    }
};
