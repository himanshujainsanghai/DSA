class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        // unordered_set<int> st(arr.begin() , arr.end());
        // int cntzero = 0;
        // for(int& it : arr){
        //     if(it==0){
        //         cntzero++;
        //         continue;
        //     }
        //     if(st.find(2*it) != st.end()){
        //         return true;
        //     }
        // }

        // if(cntzero>1){
        //     return true;
        // }

        int n =arr.size();
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i!=j && arr[j] == 2*arr[i]){
                    return true;
                }
            }
        }


        return false;
        
    }
};