// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         string ans = "";
//         stack<int> st;
//         for(int i=0 ; i<s.size() ; i++){
//             if(s[i]=='('){
//                 st.push(i);
//             }
//             else if(s[i] == ')'){
//                 if(!st.empty()){
//                     st.pop();
//                 }
//                 else{
//                     continue;
//                 }
//             }
//             ans.push_back(s[i]);
//         }

//         if(!st.empty()){
//             ans.erase(st.top() , 1);
//             st.pop();
//         }


//         return ans;
        
//     }
// };

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        // First pass: Mark invalid parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Valid pair found, pop the stack
                } else {
                    s[i] = '*'; // Mark invalid closing parenthesis
                }
            }
        }

        // Mark remaining unmatched opening parentheses
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        // Second pass: Build the result string excluding marked characters
        string ans = "";
        for (char c : s) {
            if (c != '*') {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
