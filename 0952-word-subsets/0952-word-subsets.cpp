class Solution {
public:
bool isValid(vector<int>& vis , vector<int>& freq){
    for(int i=0 ; i<26 ; i++){
        if(vis[i] < freq[i]){
            return false;
        }
    }

    return true;
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq(26,0);
        for(string &it: words2){
            vector<int> temp(26,0);
            for(char &ch : it){
                temp[ch-'a']++;
                freq[ch-'a'] = max(freq[ch-'a'] , temp[ch-'a']);
            }
        }


        for(string &word:words1){
            vector<int> vis(26,0);
            for(char &ch: word){
                vis[ch-'a']++;
            }
            if(isValid(vis , freq)){
                ans.push_back(word);
            }
        }
        

        return ans;
    }
};