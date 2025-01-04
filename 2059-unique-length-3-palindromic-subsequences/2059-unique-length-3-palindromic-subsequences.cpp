class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char , int> firstOcc;
        unordered_map<char , int> lastOcc;
        int n = s.size();

        for(int i=0 ; i<n ; i++){
            char it = s[i];
            if(firstOcc.find(it) == firstOcc.end()){
                firstOcc[it] = i;
            }
            lastOcc[it] = i;
        }
        int count =0;
        for(auto it: firstOcc){
            char ele = it.first;
            int l = it.second;
            int r = lastOcc[ele];
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