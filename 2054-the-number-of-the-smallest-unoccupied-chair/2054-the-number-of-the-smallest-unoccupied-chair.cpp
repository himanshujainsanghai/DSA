class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int index = times[target][0];
        int n = times.size();
        // vector<vector<int>> vis(n, vector<int>(3, 0));
        // for (int i = 0; i < n; i++) {
        //     vis[i][0] = times[i][0];
        //     vis[i][1] = times[i][1];
        //     vis[i][2] = i;
        // }
        // std::sort(vis.begin(), vis.end(),
        //           [](const std::vector<int>& a, const std::vector<int>& b) {
        //               return a[0] < b[0]; // Compare the first elements
        //           });(

        // vector<bool> used(n , false);
        // vector<bool> available(n ,true);

        // for(auto it : vis)

        sort(times.begin(), times.end());
        priority_queue<int, vector<int>, greater<int>> avail;
        // vector<bool> avail( n , true);
        // avail:chairIndex
        // reserved: departure_time , chairIndex
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            reserved;

        for (auto& it : times) {
            int arr = it[0];
            int depp = it[1];
            // convert the reseved chairs to available ones
            while (!reserved.empty() && reserved.top().first <= arr) {
                // avail[reserved.top().second] = true;
                avail.push(reserved.top().second);
                reserved.pop();
            }
            if (arr == index)
                break;
            if (avail.empty()) {
                reserved.push({depp, reserved.size()});

            } else {
                reserved.push({depp, avail.top()});
                avail.pop();
            }
        }
        return avail.empty() ? reserved.size() : avail.top();
    }
};