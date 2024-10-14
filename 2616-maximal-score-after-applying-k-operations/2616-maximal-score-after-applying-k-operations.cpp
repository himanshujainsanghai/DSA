class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = nums.size();
        priority_queue<int> pq(begin(nums), end(nums));
        long long cnt = 0;
        for (int ind = 0; ind < k; ind++) {
            int it = pq.top();
            pq.pop();
            cnt += it;
            pq.push(ceil(it / 3.0));
        }
        return cnt;
    }
};