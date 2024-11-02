class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> mpp;
        for (int i = n - 1; i >= 0; i--) {
            // if (st.empty()) {
            //     mpp[nums2[i]] = -1;
            // } else if (!st.empty() && nums2[i] > st.top()) {
            //     while (!st.empty() && nums2[i] > st.top()) {
            //         st.pop();
            //     }
            //     if (st.empty()) {
            //         mpp[nums2[i]] = -1;
            //     } else {
            //         mpp[nums2[i]] = st.top();
            //     }
            // } else {
            //     mpp[nums2[i]] = st.top();
            // }
            // st.push(nums2[i]);

            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]]= -1;
            }
            else{
                mpp[nums2[i]]= st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int num : nums1){
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};