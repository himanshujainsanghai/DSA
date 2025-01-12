class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 != 0) return false;
        // stack<int> open, openClose;
        // for(int i=0 ; i<n ; i++){
        //     if(locked[i] == '0'){
        //         openClose.push(i);
        //     }
        //     else if(s[i] == '('){
        //         open.push(i);
        //     }
        //     else if(s[i] == ')'){
        //         if(!open.empty()){
        //             open.pop();
        //         }
        //         else if(!openClose.empty()){
        //             openClose.pop();
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        // }

        // while(!open.empty() && !openClose.empty() && openClose.top() > open.top()){
        //     openClose.pop();
        //     open.pop();
        // }

        // if(!open.empty()) return false;


        // Left to Right and Right to Left 2 iterations Approach
        int open = 0;
        for(int i=0 ; i<n ; i++){
            if(locked[i] == '0' || s[i] == '('){
                open += 1;
            }
            else{
                open -=1;
                if(open<0) return false;
            }

        }
        open =0;
        for(int i=n-1 ; i>=0 ; i--){
            if(locked[i] == '0' || s[i] == ')'){
                open += 1;
            }
            else{
                open -=1;
                if(open<0) return false;
            }

        }
        return true;

        
    }
};