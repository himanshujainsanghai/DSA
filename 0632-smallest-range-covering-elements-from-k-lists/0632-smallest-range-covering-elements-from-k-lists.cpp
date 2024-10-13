class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int k = nums.size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // element , listindex , index

        int right = -1000000;
        for (int i = 0; i < k; i++) {
            int l = nums[i][0];
            pq.push({l, {i, 0}});
            right = max(right, l);
        }

        vector<int> range = {-1000000, 1000000};

        // now moving and shorten the window
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int left = it.first;
            int listind = it.second.first;
            int ind = it.second.second;

            if (right - left < range[1] - range[0]) {
                range[0] = left;
                range[1] = right;
            }

            if (ind + 1 < nums[listind].size()) {
                int ele = nums[listind][ind + 1];
                pq.push({ele, {listind, ind + 1}});
                right = max(right, ele);
            } else {
                break;
            }
        }

        return range;
    }
};