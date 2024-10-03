// class Solution {
//     private:
//     int n;
//     int func(int ind , int p ,vector<int>& nums , int sum , int length){
//         if(ind==0){
//             if(sum%p == 0) return length;
//             return 0;
//         }

//         // take
//         int take = func(ind-1 , p , nums , sum + nums[ind] , length++);
//         // nottake
//         int nottake = func(ind-1 , p , nums , sum , length);
//         return max(take , nottake);
//     }
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         int n = nums.size();
//         int longest = func(n-1 , p , nums , 0 , 0);
//         return n-longest;
        
//     }
// };
class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    const int remainder = accumulate(nums.begin(), nums.end(), 0L) % p;
    // const int  = sum ;
    if (remainder == 0)
      return 0;

    unordered_map<int, int> prefixToIndex{{0, -1}};
    int ans = nums.size();
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      prefix %= p;
      const int target = (prefix - remainder + p) % p;
      if (const auto it = prefixToIndex.find(target);
          it != prefixToIndex.cend())
        ans = min(ans, i - it->second);
      prefixToIndex[prefix] = i;
    }

    return ans == nums.size() ? -1 : ans;
  }
};