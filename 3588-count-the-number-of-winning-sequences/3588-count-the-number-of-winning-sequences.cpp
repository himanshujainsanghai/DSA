// class Solution {
// private:
//     int mod;
//     int n;
//     unordered_map<char, int> mpp;

//     // unordered_map<string, int> dp;

//     bool alicewin(int ap, int bp) {
//         return  ((ap == 0 && bp == 2) || (ap == 1 && bp == 0) ||
//             (ap == 2 && bp == 1)) ;
//     }

//     string getKey(int ind, int prev, int scoreDiff) {
//         return to_string(ind) + "," + to_string(prev) + "," + to_string(scoreDiff);
//     }


//     int func(int ind, string s, int prev, int scoreDiff,
//             vector<vector<vector<int>>>& dp) {
//         if (ind == n) {
//             if (scoreDiff <0)
//                 return 1;
//             return 0;
//         }

//         if (dp[ind][prev + 1][scoreDiff + n] != -1) {
//             return dp[ind][prev + 1][scoreDiff + n];
//         }

//         int take = 0;
//         for (int i = 0; i < 3; i++) {
//             if (i != prev) {
//                 if (mpp[s[ind]] != i) {
//                     if (alicewin(mpp[s[ind]], i)) {
                        
//                         take = (take + func(ind + 1, s, i, scoreDiff +1 , dp)) % mod;
                        
//                     } else {
                        
//                         take = (take + func(ind + 1, s, i, scoreDiff-1, dp)) % mod;
//                     }
//                 } else {

//                     take = (take + func(ind + 1, s, i, scoreDiff, dp)) % mod;
//                 }
//             }
//         }
//         // return take;
//         return dp[ind][prev + 1][scoreDiff + n] = take;
//     }

// public:
//     int countWinningSequences(string s) {
//         n = s.size();
//         mod = 1e9 + 7;

//         // 0->E , 1->F , 2->W
//         mpp['F'] = 0;
//         mpp['W'] = 1;
//         mpp['E'] = 2;
//         int prev = -1;

//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2 * n + 1, -1)));


//         return func(0, s, prev, 0,  dp);
//     }
// };
class Solution {
private:
    int mod;
    int n;

    // Function to check if Alice wins this round
    bool alicewin(int ap, int bp) {
        return (ap == 0 && bp == 2) || (ap == 1 && bp == 0) || (ap == 2 && bp == 1);
    }

    // Recursive function to count winning sequences with memoization
    int func(int ind, string& s, int prev, int scoreDiff, unordered_map<char, int>& mpp, vector<vector<vector<int>>>& dp) {
        // Base case: if we've processed the whole string
        if (ind == n) {
            return (scoreDiff < 0) ? 1 : 0; // Bob wins if his score is greater than Alice's
        }

        // Check if the result for the current state is already computed
        if (dp[ind][prev + 1][scoreDiff + n] != -1) {
            return dp[ind][prev + 1][scoreDiff + n];
        }

        int take = 0;

        // Try all possible choices for the next move (0, 1, 2 corresponding to E, F, W)
        for (int i = 0; i < 3; i++) {
            if (i != prev) {
                if (mpp[s[ind]] != i) { // If the current move is different from the string's current move
                    if (alicewin(mpp[s[ind]], i)) {
                        // Alice wins this round, scoreDiff increases
                        take = (take + func(ind + 1, s, i, scoreDiff + 1, mpp, dp)) % mod;
                    } else {
                        // Bob wins this round, scoreDiff decreases
                        take = (take + func(ind + 1, s, i, scoreDiff - 1, mpp, dp)) % mod;
                    }
                } else {
                    // If the move is the same as the current character, continue without changing scores
                    take = (take + func(ind + 1, s, i, scoreDiff, mpp, dp)) % mod;
                }
            }
        }

        // Store the computed result in the memoization table
        return dp[ind][prev + 1][scoreDiff + n] = take;
    }

public:
    int countWinningSequences(string s) {
        n = s.size();
        mod = 1e9 + 7;

        // Mapping 'F' -> 0, 'W' -> 1, 'E' -> 2
        unordered_map<char, int> mpp;
        mpp['F'] = 0;
        mpp['W'] = 1;
        mpp['E'] = 2;

        // Initialize a 3D DP table with dimensions (n x 4 x 2n+1)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2 * n + 1, -1)));

        // Start the recursive process with score difference initialized to 0
        return func(0, s, -1, 0, mpp, dp);
    }
};
