// class Solution {
//     private:
//     int getDigitSum(int num){
//         int sum =0;
//         while(num>0){
//             sum += num%10;
//             num = num/10;
//         }
//         return sum;
//     }
// public:
//     int maximumSum(vector<int>& nums) {
//         unordered_map<int , int> mpp;
//         int ans=-1;
//         for(int i=0 ; i<nums.size() ; i++){
//             int number = getDigitSum(nums[i]);
//             if(mpp.find(number) == mpp.end()){
//                 mpp[number] = nums[i];
//             }
//             else{
//                 ans = max(ans , nums[i]+mpp[number]);
//                 mpp[number] = max(mpp[number] , nums[i]);
//             }

//         }
//         return ans;
//     }
// };

// using vector instead of map
class Solution {
public:
    int sumDigits(int numb) {
        int sum=0;
        while(numb) {
            sum+=numb%10;
            numb/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> sameDigit(82, -1);
        int sum, maxSum=-1;
        for(int i=0; i<nums.size(); i++) {
            sum=sumDigits(nums[i]);
            if(sameDigit[sum]!=-1) {
                maxSum=max(maxSum, sameDigit[sum]+nums[i]);
                sameDigit[sum]=max(sameDigit[sum], nums[i]);
            } else {
                sameDigit[sum]=nums[i];
            }
        }
        return maxSum;
    }
};