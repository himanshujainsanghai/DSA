class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstOcc(26 ,-1) , lastOcc(26,-1);
        for(int i=0 ; i<n ; i++){
            int it = s[i]-'a';
            if(firstOcc[it] == -1){
                firstOcc[it] = i;
            }
            lastOcc[it] = i;
        }
        int count =0;
        for(int it=0 ; it<26 ; it++){
            int l = firstOcc[it];
            int r = lastOcc[it];
            if(l==r) continue;
            unordered_set<char> st;
            for(int i=l+1 ; i<=r-1 ; i++){
                st.insert(s[i]);
            }

            count += st.size();
        }
        return count;
        
    }
};