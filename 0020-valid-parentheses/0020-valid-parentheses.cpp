class Solution {
public:
    bool isValid(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);        
        int n = s.size();
        if(n==0) return true;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char ch = st.top();
                if (s[i] == ')' && ch == '(' 
                || s[i] == '}' && ch == '{' ||
                s[i] == ']' && ch == '['){
                    st.pop();

                }else{
                    return false;
                }

            }

        }
        return (st.size() == 0);
    }
};