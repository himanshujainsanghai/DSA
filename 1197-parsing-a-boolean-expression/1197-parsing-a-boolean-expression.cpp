class Solution {
    public:
    char solve(vector<char>& vis, char op) {
        if (op == '!') {
            return (vis[0] == 't') ? 'f' : 't';
        } else if (op == '&') {
            return any_of(vis.begin(), vis.end(),
                          [](char ch) { return ch == 'f'; })
                       ? 'f'
                       : 't';
        } else {
            return any_of(vis.begin(), vis.end(),
                          [](char ch) { return ch == 't'; })
                       ? 't'
                       : 'f';
        }
        return 't';
    }

public:
    bool parseBoolExpr(string exp) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = exp.size();
        if (n == 1)
            return (exp[0] == 't');
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (exp[i] == ',') {
                continue;
            } else if (exp[i] == ')') {
                vector<char> vis;
                while (st.top() != '(') {
                    vis.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(vis, op));
            } else {
                st.push(exp[i]);
            }
        }

        return (st.top() == 't') ? true : false;
    }
};