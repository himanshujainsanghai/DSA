class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()) return false;
        vector<int> vis(26,0);
        for(char ch:s){
            vis[ch-'a']++;
        }
        int count = 0;
        for(int i=0 ; i<26 ; i++){
            if(vis[i]%2 != 0){
                count++;
            }
        }

        if(count <=k) return true;
        return false;
        
    }
};