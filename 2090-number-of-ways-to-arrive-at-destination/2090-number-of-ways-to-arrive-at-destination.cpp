class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        constexpr int mod = 1e9 + 7;


        vector<pair<int , int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});

        }


        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n ,0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long , int > , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
        pq.push({0 , 0});

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            // auto [dis , node ] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int edw = iter.second;
                long long newd = edw + dis;
                // 1st time arrival
                if(newd <dist[adjnode]){
                    dist[adjnode] = newd;
                    ways[adjnode] = ways[node];
                    pq.push({newd , adjnode}); 
                }
                // next arrival

                else if(newd == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod; 
                }
            }
        }
        return ways[n-1] % mod;
        
    }
};