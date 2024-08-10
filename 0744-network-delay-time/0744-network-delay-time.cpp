// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int , int>>> adj(n+1);
//         for(auto it:times){
//             adj[it[0]].push_back({it[1] , it[2]});
//         }
//         vector<int> dist(n , INT_MAX);
//         dist[k] = 0;
//         priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
//         pq.push({0 , k});
//         while(!pq.empty()){
//             int dis = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();

//             if(dis > dist[node]) continue;
//             for(auto it:adj[node]){
//                 int newd = it.second;
//                 int newnode = it.first;

//                 int newdis = newd + dis;
//                 if( newdis != INT_MAX && newdis < dist[newnode] ){
//                     dist[newnode] = newdis;
//                     pq.push({newdis , newnode});
//                 }
//             }

//         }
//         int max_time = *max_element(dist.begin() + 1, dist.end());
//         return max_time == INT_MAX ? -1 : max_time;        
//     }
// };


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        // for (const auto& time : times) {
        //     adj[time[0]].emplace_back(time[1], time[2]);
        // }
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});  
        }

        // Initialize the min-heap (priority queue)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.emplace(0, k);

        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto [curr_time, node] = pq.top();
            pq.pop();

            if (curr_time > dist[node]) continue;

            for (const auto& [neighbor, time] : adj[node]) {
                int new_time = curr_time + time;
                if (new_time < dist[neighbor]) {
                    dist[neighbor] = new_time;
                    pq.emplace(new_time, neighbor);
                }
            }
        }

        // Find the maximum time required to reach any node
        int max_time = *max_element(dist.begin() + 1, dist.end());
        
        // If any node is unreachable, return -1
        return max_time == INT_MAX ? -1 : max_time;
    }
};
