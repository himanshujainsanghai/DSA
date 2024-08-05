class DisjointSet{
    
    private:
    vector<int> rank , parent , size;
    
    
    public:
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0 ; i<n ;i++){
            parent[i]=i;
            size[i] =1;
        }
        
    }
    
    int findpar(int node){
        if(node == parent[node]){
            return node;
            
        }
        return parent[node] = findpar(parent[node]);
    }
    
    void unionByRank(int  u , int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int  u , int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string , int> mpp;
        DisjointSet ds(n);
        for(int i =0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionBySize(i , mpp[mail]);
                }
            }
        }
        vector<string> mergedmail[n];
        for(auto it:mpp){
            string mail = it.first;
            int node = ds.findpar(it.second);
            mergedmail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i =0 ; i<n ; i++){
            if(!mergedmail[i].empty()){
                sort(mergedmail[i].begin() , mergedmail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto it : mergedmail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};