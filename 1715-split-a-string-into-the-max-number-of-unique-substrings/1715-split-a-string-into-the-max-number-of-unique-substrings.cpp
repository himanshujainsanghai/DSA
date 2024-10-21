class Solution {

    private:
    void func(string s , int i ,unordered_set<string>& st , int currcnt , int& maxcnt){

        // PRUNING
        if(currcnt + (s.size()-i) <= maxcnt){
            return;
        }

        if(i>=s.length()){
            maxcnt = max(maxcnt , currcnt);
            return;
        }

        for(int j=i ; j<s.size() ; j++){
            string sub = s.substr(i , j-i+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                func(s,j+1 , st , currcnt+1 , maxcnt);
                st.erase(sub);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxcnt =0 ;
        int currcnt =0;
        func(s , 0 , st , currcnt , maxcnt);
        
        return maxcnt;
    }
};