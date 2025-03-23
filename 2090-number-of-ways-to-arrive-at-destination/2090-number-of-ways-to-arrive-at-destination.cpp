class Solution {
public:
    typedef pair<long long , int> P; //weight(time), node
    int M = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int , vector<pair<int , int>>> adj;
        for(auto &road :roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v , time});
            adj[v].push_back({u , time});
        }

        priority_queue<P , vector<P> , greater<P>> pq;
        vector<long long> result(n , LLONG_MAX);
        vector<int> count(n ,0);
        result[0]=0;
        count[0]=1;
        pq.push({0 , 0});

        while(!pq.empty()){
            int currNode = pq.top().second;
            long long currWeight = pq.top().first;
            pq.pop();

            for(auto &vec:adj[currNode]){
                int ngbr = vec.first;
                int time = vec.second;

                if(currWeight + time < result[ngbr]){
                    result[ngbr] = currWeight + time;
                    pq.push({currWeight + time , ngbr});
                    count[ngbr] = count[currNode];
                }
                else if(currWeight + time == result[ngbr]){
                    count[ngbr] = (count[ngbr]+count[currNode])%M;
                }
            }

        }

        return count[n-1];
    }
};