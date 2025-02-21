class Solution {
public:
    // int minFlips(int a, int b, int c) {
    //     int flips = 0;
    //     while(a!=0 || b!=0 || c!=0){
    //         // check most significant bit or rightmost bit
    //         if((c&1) == 1){
    //             if((a&1)==0 && (b&1)==0){
    //                 flips++;
    //             }
    //         }
    //         else{
    //             if((a&1) == 1) flips++;
    //             if((b&1) == 1) flips++;
    //         }

    //         // right shift each of them
    //         a >>= 1;
    //         b >>= 1;
    //         c >>= 1;


    //     }

    //     return flips;
        
    // }


    int minFlips(int a , int b , int c){
        int result = ((a|b) ^ c);

        // missing case where both 1 are there

        int result1 = (a&b);
        int result2 = (result1 & result);

        return __builtin_popcount(result) + __builtin_popcount(result2);
    }
};