class Solution {
public:
    int hammingWeight(int n) {
        // int  count = 0;
        // for(int i=31 ; i>=0 ; i--){
        //     if(((n >> i) & 1) == 1) count++;
        // }
        // return count;


        // approach 2 : unset the rigthmost set bit
        int count = 0;
        while(n>0){
            n= n & (n-1);
            count++;
        }
        return count;
    }
};