// class Solution {
//     private:
//     bool func(int ind ,vector<int>& arr, int k , vector<int>& ifpaired ){
//         if(ind <=0) return true;

//         for(int i = ind-1 ; i >=0 ; i--){
//             if(ifpaired[i] == 0 && (arr[i]+arr[ind])%k == 0){
//                 ifpaired[i] =1;
//                 if(func(ind-1 , arr , k , ifpaired) == true){
//                     return true;
//                 }else ifpaired[i] = 0;
//             }
//         }
//         return false;
//     }
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> ifpaired(n , 0);
//         if(func(n-1 , arr , k , ifpaired) == true) return true;
//         return false;
        
//     }
// };
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // Count the remainders
        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // To handle negative numbers
            remainderCount[remainder]++;
        }
        
        // Check if pairs can be formed
        if (remainderCount[0] % 2 != 0) return false; // Remainder 0 must have an even count
        
        for (int i = 1; i <= k / 2; i++) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; // Remainder `i` should match its complement `k - i`
            }
        }
        
        return true;
    }
};
