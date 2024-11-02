class Solution {
public:
    bool isCircularSentence(string s) {
        char first = s[0];
        if(first != s.back()){
            return false;
        }

        for(int i=1 ; i<s.size() ; i++){
            if(s[i] != ' '){
                continue;
            }
            else{
                if(s[i-1] != s[i+1]){
                    return false;
                }
            }
        }

        return true;
        
    }
};