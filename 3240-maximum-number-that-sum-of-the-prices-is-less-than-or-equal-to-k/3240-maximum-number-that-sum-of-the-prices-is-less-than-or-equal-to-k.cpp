// class Solution {
// public:
//     typedef long long ll;
//     void getBits(ll num , vector<ll>& bitCount){
//         // base cases
//         if(num==0) return;
//         if(num == 1){
//             bitCount[0] += 1;
//             return;
//         }
//         if(num==2){
//             bitCount[0] += 1;
//             bitCount[1] += 1;
//             return;
//         }
//         ll powerOf2 = log2(num);
//         // ll nearestOne = power(2 , powerOf2);
//         ll nearestOne = (1ll << powerOf2);

//         bitCount[powerOf2] += (num - nearestOne +1);

//         for(int i=powerOf2-1 ; i>=0 ; i--){
//             bitCount[i] += (nearestOne /2);
//         } 
//         getBits(num-nearestOne , bitCount);
//         return;

//     }
//     long long findMaximumNumber(long long k, int x) {
//         ll low = 0;
//         ll high = 1e15;
//         ll result = 0;

//         while(low <= high){
//             ll mid = low + (high-low)/2;
//             vector<ll> bitCount(65 , 0);
//             getBits(mid , bitCount);

//             ll accuCount = 0;
//             for(ll i=0 ; i<log2(mid)+1 ; i++){
//                 if((i+1) % x == 0){
//                     accuCount += bitCount[i];
//                 }
//                 else continue;
//             }

//             if(accuCount <= k){
//                 result = mid;
//                 low = mid+1;
//             }
//             else{
//                 high = mid-1;
//             }
//         }

//         return result;
        
//     }
// };
class Solution {
public:
    long long fun(long long mid, long long k, long long x) {
        long long rows = mid + 1;
        int bitLen = 0;
        while (mid > 0) {
            bitLen++;
            mid >>= 1; // Right shift mid by 1 each time
        }
        // Optimized bit length calculation

        long long ttlBit = 0;
        for (int i = x; i <= bitLen;i++) {   
            if(i%x!=0) continue;
            long long powerOfI = (1LL << i); // 2^i
            long long powerOfI_1 = (1LL << (i - 1)); // 2^(i-1)

            long long fullPacket = rows / powerOfI;
            ttlBit += fullPacket * powerOfI_1;

            long long remaining = rows % powerOfI;
            if (remaining >= powerOfI_1) {
                ttlBit += remaining - powerOfI_1;
            }
        }
        return ttlBit;
    }

    long long findMaximumNumber(long long k, int x) {
        long long s = 0, e = 1e15,
                  mid; 
        while (s <= e) {
            mid = s + (e - s) / 2; 
            long long cntBits = fun(mid, k, x);
            if (cntBits <= k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return e;
    }
};