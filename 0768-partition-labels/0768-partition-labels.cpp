class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> vis(26 , 0);
        for(int i=0 ; i<n ; i++){
            vis[s[i]-'a'] = i;
        }
        int i=0 , j=0 , end =0;
        vector<int> result;
        while(i<n){
            end = vis[s[i]-'a'];
            while(j<end){
                end = max(end , vis[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i=end+1;
        }

        return result;
        
    }
};