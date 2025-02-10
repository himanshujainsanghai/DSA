class Solution {
public:
    string clearDigits(string s) {
        // stack<char> st;
        // int i=0;
        // while(i<s.size()){
        //     if(isdigit(s[i])){
        //         st.pop();
        //     }
        //     else{

        //     st.push(s[i]);
        //     }
        //     i++;
        // }
        // if(st.empty()) return "";
        // string ans = "";
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }   
        // reverse(ans.begin() , ans.end());
        // return ans;


        int n = s.size();
        string ans = "";
        for(int i=0 ; i<n ; i++){
            if(isdigit(s[i])){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};