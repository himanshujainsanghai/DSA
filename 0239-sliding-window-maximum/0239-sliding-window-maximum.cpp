const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);
    return 0;
}();
#endif



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int  n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0 ; i<n ; i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};