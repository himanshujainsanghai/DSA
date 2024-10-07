class Solution {
public:
    int minLength(string s) {
        // stack<char> st;
        // for (int i = 0; i < s.size(); i++) {
        //     char curr = s[i];
        //     if (!st.empty() && ((curr == 'B' && st.top() == 'A') || (curr == 'D' && st.top() == 'C'))) {
        //         st.pop();  
        //     } else {
        //         st.push(curr);  
        //     }
        // }
        // return st.size();

        // most optimal solution-->
        int n = s.size();
        int i=0 , j=1;
        while(j<n){
            if(i<0){
                i++;
                s[i] = s[j];
            }
            else if(( s[i] == 'A' && s[j] == 'B') || ( s[i] == 'C' && s[j] == 'D')){
                i--;

            }
            else{
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i+1;
    }
};
