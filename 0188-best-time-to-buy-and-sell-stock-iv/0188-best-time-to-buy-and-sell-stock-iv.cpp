class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<int> ahead(2*k+1,0);
        for(int ind =n-1 ; ind>=0 ; ind--){
            for(int t =0 ; t<=2*k-1 ; t++){
                if(t%2 == 0){
                ahead[t] = max(-p[ind] + ahead[t+1] , ahead[t]);
                }
                else{
                ahead[t] = max(p[ind] + ahead[t+1] , ahead[t]);

                }
            }
        }
        return ahead[0];
    }
};