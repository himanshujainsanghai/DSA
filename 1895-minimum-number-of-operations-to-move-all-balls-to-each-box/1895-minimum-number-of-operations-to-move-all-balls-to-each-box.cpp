class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n , 0);
        int cumSum = 0 , totalPrevSum = 0;
        for(int i=0 ; i<n ; i++){
            ans[i] += totalPrevSum;
            cumSum += boxes[i]-'0';
            totalPrevSum += cumSum;

        }
        cumSum = 0 , totalPrevSum = 0;
        for(int i=n-1 ; i>=0 ; i--){
            ans[i] += totalPrevSum;
            cumSum += boxes[i]-'0';
            totalPrevSum += cumSum;
        }

        return ans;
        
    }
};