class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = s.size();
        if(n<3){
            return s;
        }
        string ans ="";
        int cnt =1;
        ans += s[0];
        for(int i=1 ; i<n ; i++){
            if(s[i] != s[i-1]){
                ans += s[i];
                cnt =1;
            }
            else if(s[i]==s[i-1] && cnt <2){
                ans += s[i];
                cnt++;
            }
            else if(s[i] == s[i-1] && cnt>=2){
                // cnt++;
                continue;
            }

        }

        return ans;
        
    }
};