class Solution {
public:
    int maxDepth(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);        
        int n = s.size();
        int res = 0 , curr =0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                curr++;
                res = max(res , curr);
            }
            if(s[i] == ')'){
                curr--;
            }
        }
        return res;
        
    }
};