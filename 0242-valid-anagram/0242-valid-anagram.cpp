class Solution {
public:
    bool isAnagram(string s, string t) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        if (s.size() != t.size())
            return false;

        // Approach1 : TC=O(N) while SC=O(2*sizeOfString); 
        // unordered_map<int, int> mpp1, mpp2;
        // for (int i = 0; i < s.size(); i++) {
        //     mpp1[s[i] - 'a']++;
        //     mpp2[t[i] - 'a']++;
        // }
        // return mpp1 == mpp2;
        
        // Approach 2 TC=O(2*nlogn) , SC=O(1)
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());
        // return s==t;

        // Approach 3
        vector<int> frq(26,0);
        for(int i=0 ; i<s.size() ; i++){
            frq[s[i]-'a']++;
            frq[t[i]-'a']--;
        }
        for(auto &count:frq){
            if(count != 0) return false;
        }
        return true;
    }
};