class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
         int n = nums.size();
         int maxi = *max_element(nums.begin() , nums.end());
         int i=0 , j=0 , maxiCount = 0;
         long long  result = 0;
          while (j < n) {
            if (nums[j] == maxi) {
                maxiCount++;
            }

            while (maxiCount == k) {
                result += n - j;
                if (nums[i] == maxi) maxiCount--;
                i++;
            }

            j++;
        }

         return result;
        
    }
};