class Solution {
public:
    typedef long long ll;
    int m = 1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        ll aXorx = 0;
        ll bXorx = 0;

        // we have to map the the values of a and b that are not sighnificant to xor with x
        for(int i=49 ; i>=n ; i--){
            bool a_ith_bit = ((a >> i) & 1) >0;
            bool b_ith_bit = ((b >> i) & 1) >0;

            if(a_ith_bit){
                aXorx = (aXorx ^ (1ll<<i));
            }
            if(b_ith_bit){
                bXorx = (bXorx ^ (1ll<<i));
            }

        }

        // map n-1th bit to the 0th bit in x
        for(int i=n-1 ; i>=0 ; i--){
            bool a_ith_bit = ((a >> i) & 1) >0;
            bool b_ith_bit = ((b >> i) & 1) >0;

            if(a_ith_bit == b_ith_bit){
                aXorx = (aXorx ^ (1ll<<i));
                bXorx = (bXorx ^ (1ll<<i));
                continue;
            }
            if(aXorx > bXorx){
                bXorx = (bXorx ^ (1ll<<i));
            }
            else{
                aXorx = (aXorx ^ (1ll<<i));
            }

        }


        aXorx %= m;
        bXorx %= m; 
        return (aXorx*bXorx)%m;
    }
};