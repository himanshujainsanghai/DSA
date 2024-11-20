class Solution {
public:
    int takeCharacters(string s, int k) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = s.size();
        if(n<3*k){
            return -1;
        }

        vector<int> mpp(3 ,0);
        for(int i=0 ; i<n ; i++){
            mpp[s[i]-'a']++;
        }


        if(mpp[0]<k || mpp[1]<k || mpp[2]<k){
            return -1;
        }

        int i=0 , j=0;
        int ans = 0;

        while(j<n){
            mpp[s[j]-'a']--;

            while(i<=j && (mpp[0]<k || mpp[1]<k || mpp[2]<k)){
                mpp[s[i]-'a']++;
                i++;


            }
            ans = max(ans, j-i+1);
            j++;
        }

        return n-ans;
        
    }
};