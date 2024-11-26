class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vis(n , 0);

        for(auto& edge:edges){
            vis[edge[1]]++;
        }

        int cnt =0;
        int champ=-1;
        for(int i=0 ; i<n ; i++){
            if(vis[i]==0){
                champ = i;
                cnt++;
                if(cnt>1){
                    return -1;
                }
            }
        }

        return champ;
    }
};