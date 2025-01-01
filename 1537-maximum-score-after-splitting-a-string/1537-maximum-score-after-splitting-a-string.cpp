class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            char it = s[i]-'0';
            sum += it;
        }
        int maxi = 0 , prevsum =0;
        for(int i=0 ; i<n-1 ; i++){
            int it = s[i]-'0';
            prevsum += it;
            int numberOfZeroes = (i+1)-prevsum;
            int rightOnes = sum-prevsum;
            maxi = max(maxi ,numberOfZeroes + rightOnes );

        }

        return maxi;
        
    }
};