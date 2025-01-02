class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> charSet = {'a' , 'e' , 'i' , 'o' , 'u'};
        int n = words.size();
        vector<int> vis(n , 0);
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if((charSet.find(words[i][0]) != charSet.end()) && (charSet.find(words[i].back()) != charSet.end())){
                count++;
            }
            vis[i]=count;
        }

        int m = queries.size();
        vector<int> ans(m , 0);
        for(int i=0 ; i<m ; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
                ans[i] = vis[r];
            }
            else{

            ans[i] = vis[r]-vis[l-1];
            }
        }

        return ans;
        
    }
};