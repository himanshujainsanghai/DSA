// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         ios::sync_with_stdio(false); // Disable synchronization with C I/O
//         cin.tie(NULL);               // Untie cin from cout
//         cout.tie(NULL);

//         long long num =x;
//         for(int i=1 ; i<n ; i++){
//             num = (num+1) | x;
//         }

//         return num;
        
//     }
// };

class Solution {
public:
    long long minEnd(int n, int x) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        vector<short> shifts;
        long long cur = x;
        long long calc = n - 1;
        
        for(int i = 0; i < 32; i++) //find bit positions in x which are 0
            if(!((1 << i) & x))
                shifts.push_back(i);
        for(int i = 32; i < 64; i++)
            shifts.push_back(i);

// for(auto x: shifts) cout<<x<<' ';
        
        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1) << shifts[i];
        }
        return cur;
    }
};