// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i=0 , j=0;
//         long long ans = 0;
//         long long windowsum = 0;
//         unordered_set<int> st;
//         while(j<n){

//             // check if element is present clear the set till that indexed element
//             while(st.count(nums[j])){
//                 windowsum -= nums[i];
//                 st.erase(nums[i]);
//                 i++;
//             }

//             windowsum += nums[j];
//             st.insert(nums[j]);

//             if(j-i+1 == k){
//                 ans = max(ans , windowsum);

//                 st.erase(nums[i]);
//                 windowsum -= nums[i];
//                 i++;
//             }

//             j++;
//         }


//         return ans;
        
//     }
// };


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long ans = 0, windowSum = 0;
        unordered_map<int, int> freq; // Frequency map for elements in the window

        for (int j = 0; j < n; ++j) {
            // Add current element to the window
            windowSum += nums[j];
            freq[nums[j]]++;

            // Shrink window if it contains duplicates or exceeds size k
            while (freq[nums[j]] > 1 || (j - i + 1) > k) {
                windowSum -= nums[i];
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]); // Remove from map if frequency is 0
                i++;
            }

            // Update result if the window size equals k
            if (j - i + 1 == k) {
                ans = max(ans, windowSum);
            }
        }

        return ans;
    }
};
