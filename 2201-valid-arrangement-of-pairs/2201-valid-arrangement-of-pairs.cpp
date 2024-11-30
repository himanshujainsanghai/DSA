class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int , vector<int>> adj; // adjacency list
        unordered_map<int , int> indeg , outdeg;
        //node->degree


        for(auto& pair: pairs){
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }

        // now lets find out the startNode = (outdeg-indeg == 1)
        int startNode = pairs[0][0];
        for(auto& it: adj){
            int node = it.first;
            if(outdeg[node]-indeg[node] == 1){
                startNode = node;
                break;
            }
        }


        vector<int> eulerPath;  // vector that will store our path
        stack<int> st;  
        st.push(startNode);
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nghbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nghbr);

            }
            else{
                eulerPath.push_back(curr);
                st.pop();
            }
        }

        reverse(begin(eulerPath) , end(eulerPath));
        int s = eulerPath.size();
        vector<vector<int>> ans;
        for(int i=0 ; i<s-1 ; i++){
            vector<int> temp;
            temp.push_back(eulerPath[i]);
            temp.push_back(eulerPath[i+1]);
            ans.push_back(temp);

        }

        return ans;
    }
};