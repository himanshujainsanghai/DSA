class Solution {
    private:
    bool result ;
    void solve(int ind , string s1 , string s2 , int n){
        if(ind == n){
            if(s2.find(s1) != string::npos){
                result = true;
            }
            return;
        }

        for(int i = ind ; i<n ; i++){
            swap(s1[i] , s1[ind]);
            solve(ind+1 , s1 , s2 , n);
            swap(s1[i] ,s1[ind]);
            if(result == true) return;
        }
    }
public:
    bool checkInclusion(string s1, string s2) {
        // int n = s1.size();

        // result = false;
        // solve( 0, s1, s2 , n);
        // return result;

        // BETTER APPROACH-->
        // int n = s1.size();
        // int m = s2.size();
        // if(n>m) return false;
        // sort(s1.begin() , s1.end());
        // for(int i =0 ; i<=m-n ; i++){
        //     string subs = s2.substr(i, n);
        //     sort(begin(subs) , end(subs));
        //     if(s1 == subs) return true;
        // }
        // return false;

        // Optimal Approach-->SLINDING WINDOW
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> s1_freq(26 ,0) , s2_freq(26 ,0);
        for(char &ch : s1){
            s1_freq[ch-'a']++;
        }
        int i =0 , j=0;
        while(j<m){
            s2_freq[s2[j] - 'a']++;
            if(j-i+1 > n){ //time to shrink the window
                s2_freq[s2[i] - 'a']--;
                i++;
            }
            if(s1_freq == s2_freq) return true;
            j++;
        }
        return false;


        
    }
};