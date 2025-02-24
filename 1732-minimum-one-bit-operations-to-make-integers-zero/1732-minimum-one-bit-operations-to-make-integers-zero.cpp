// class Solution {
// public:
//     int minimumOneBitOperations(int n) {
//         if(n==0) return 0;
//         vector<long long> f(31, 0);
//         f[0]=1;
//         for(int i=1 ; i<=30 ; i++){
//             f[i] = 2*f[i-1] +1;
//         }

//         int result = 0;
//         int sign = 1;
//         for(int i=30 ; i>=0 ; i--){
//             int ith_bit = ((1 << i) & n);
//             if(ith_bit == 0) continue;

//             result += sign*f[i];
//             sign *= -1;
//         }

//         return result;
//     }
// };

#include <vector>
using namespace std;

class Solution {
private:
    vector<long long> f;

public:
    Solution() {
        f.resize(31, 0);
        f[0] = 1;
        for (int i = 1; i <= 30; i++) {
            f[i] = 2 * f[i - 1] + 1;
        }
    }

    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int result = 0;
        int sign = 1;
        for (int i = 30; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {  // Check if the i-th bit is set
                result += sign * f[i];
                sign *= -1;
            }
        }

        return result;
    }
};
