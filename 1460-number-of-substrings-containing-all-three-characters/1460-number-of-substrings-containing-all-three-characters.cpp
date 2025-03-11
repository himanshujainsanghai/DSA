class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> vis(3,0);
        int n = s.size();
        int i=0 , j=0;
        int result = 0;
        while(j<n){
            vis[s[j]-'a']++;
            while(vis[0]>0 && vis[1]>0 && vis[2]>0){
                result += n-j;
                vis[s[i]-'a']--;
                i++;
            }
            j++;

        }       
        return result; 
    }
};