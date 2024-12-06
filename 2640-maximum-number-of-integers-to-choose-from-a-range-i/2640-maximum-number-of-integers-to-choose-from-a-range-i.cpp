class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin() , banned.end());
        int count =0 , sum =0;
        int j=0;


        cout<<endl;

        for(int i=1 ; i<=n ; i++){
            // check that it must be in the banned
            // if(j<banned.size() && i != banned[j]){
            //     sum += i;
            //     if(sum > maxSum){
            //         break;
            //     }
            //     else{
            //         count++;
            //     }


            // }else{
            //     j++;
            // }


            if(st.count(i)){
                continue;
            }
            

            if(sum + i <= maxSum){
               
                count++;
                sum += i;
            }else{
                break;
            }
        }


        return count;
        
    }
};