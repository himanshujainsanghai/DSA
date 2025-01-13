// class Solution {
// public:
//     int minimumLength(string s) {
//         int n = s.size();
//         int deleted = 0;
//         vector<int> freq(26,0);
//         for(int i=0 ; i<n ; i++){
//             freq[s[i]-'a']++;
//             if(freq[s[i]-'a']==3){
//                 freq[s[i]-'a'] -=2;
//                 deleted += 2;
//             }
//         }

//         return n-deleted;
        
//     }
// };

class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<int>ct(26);
        for(char c:s) ct[c-'a']++;
        int res = 0;
        for(int i=0;i<26;i++) res += (ct[i]%2? 1 : (ct[i]? 2 : 0));
        return res;
    }
};