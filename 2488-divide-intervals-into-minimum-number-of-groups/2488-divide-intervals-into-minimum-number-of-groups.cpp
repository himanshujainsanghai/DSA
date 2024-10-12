class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : intervals) {
            int st = it[0];
            int end = it[1];
            if (!pq.empty() && st > pq.top()) {
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};