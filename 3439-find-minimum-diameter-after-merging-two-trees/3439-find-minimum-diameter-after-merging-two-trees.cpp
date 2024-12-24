class Solution {
    private:

    pair<int , int> BFS(unordered_map<int , vector<int>>& adj , int source){
        queue<int> que;
        que.push(source);
        unordered_map<int , bool> vis;
        vis[source] = true;

        int farthestNode = source;
        int distance = 0;

        while(!que.empty()){
            int n = que.size();
            while(n--){
                farthestNode = que.front();
                que.pop();
                
                for(auto& it: adj[farthestNode]){
                    if(vis[it] == false){
                        vis[it] = true;
                        que.push(it);
                    }
                }
            }
            if(!que.empty()){
                distance += 1;
            }
        }

        return {farthestNode , distance};
    }
    int findDaimeter(unordered_map<int , vector<int>>& adj){
        // step1 : find the farthest node from any random node -> 0(let)
        auto [farthestNode , dist] = BFS(adj , 0);

        // step2 : the farthestNode is the gauranteed 1 end of daimeter
        // step3: find the 2nd node of Daimeter  from farthestNode and the distance will be the daimeter
        auto [secondNode , daimeter] = BFS(adj , farthestNode);

        return daimeter;
        
    } 
   
    
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);

        unordered_map<int , vector<int>> adj1;
        int u, v;
        for(auto edge:edges1){
            u = edge[0];
            v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        unordered_map<int , vector<int>> adj2;
        for(auto edge:edges2){
            u = edge[0];
            v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int d1 = findDaimeter(adj1);
        int d2 = findDaimeter(adj2);

        return max({d1 , d2 , (d1+1)/2 + (d2+1)/2 + 1 });
    }
};