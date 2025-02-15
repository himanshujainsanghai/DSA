// class Solution {
// public:
//     vector<int> nums;
//     unordered_map<int, int> mpp;
//     int currSum = 0;
//     bool check(int num, int currnum, int target) {
//         if (num == 0) {
//             return currnum == target;
//         }

//         return check(num / 10, currnum + num % 10, target) ||
//                check(num / 100, currnum + num % 100, target) ||
//                check(num / 1000, currnum + num % 1000, target) ||
//                check(num / 10000, currnum + num % 10000, target);
//     }
//     Solution() {
//         for (int i = 1; i <= 1000; i++) {
//             int sq = i * i;
//             if (check(sq, 0, i) == true) {
//                 currSum += sq;
//                 mpp[i] = currSum;
//                 nums.push_back(i);
//             } else
//                 continue;
//         }
//     }

//     static Solution& getInstance() {
//         static Solution instance;
//         return instance;
//     }

//     int punishmentNumber(int n) {
//         if (mpp.find(n) != mpp.end()) {
//             return mpp[n];
//         }
//         auto lower = std::lower_bound(nums.begin(), nums.end(), n);
//         if (lower == nums.begin())
//             return 0; // Safe bound check

//         --lower;
//         return mpp[*lower];
//     }
// };

class Solution {
public:
    int nums[1001];
    bool check(int num, int currnum, int target) {
        if (num == 0) {
            return currnum == target;
        }

        return check(num / 10, currnum + num % 10, target) ||
               check(num / 100, currnum + num % 100, target) ||
               check(num / 1000, currnum + num % 1000, target) ||
               check(num / 10000, currnum + num % 10000, target);
    }
    Solution() {
        for (int i = 1; i <= 1000; i++) {
            int sq = i * i;
            if (check(sq, 0, i) == true) {
                nums[i] = sq;
            } 
            else nums[i] = 0;
        }
        nums[0]=0;
        for(int i=1 ; i<=1000 ; i++){
            nums[i] += nums[i-1];
        }
    }

    static Solution& getInstance() {
        static Solution instance;
        return instance;
    }

    int punishmentNumber(int n) {
        return nums[n];
    }
};