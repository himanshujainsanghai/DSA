class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);


        // string ans = "";
        int i=0 , j=0 , resultindex =0;
        int n = s.size() , m = spaces.size();
        char result[n+m];

        while(i<n){
            if(j<m && i==spaces[j]){
                // ans += ' ';
                result[resultindex++] = ' ';
                j++;
            }
            // ans += s[i];
            // i++;
            result[resultindex++] = s[i++];
        }

        return string(result , n+m);
        
    }
};