class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0 , open =0;
        int n = s.size();
        for(int i =0 ; i<n ; i++){
            if(s[i] == '('){
                size++;
            }
            else if(size>0){
                size--;
            }
            else{
                open++;
            }
        }
        return size+open;
        
    }
};