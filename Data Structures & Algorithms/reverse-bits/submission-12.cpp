class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int bit = 31;
        uint32_t res = 0;

        while(bit >= 0){

            if(n & 1){

                res += (1u << bit);

            }
            n >>= 1;
            bit --;
        }
        return res;

    }
};
