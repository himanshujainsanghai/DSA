class Solution {
private:
bool isSubsetSum(vector<int>& arr, int sum , int n){
        vector<bool> prev(sum+1 , 0) , curr(sum+1 , 0);
        prev[0] = curr[0] = true;
        // prev[arr[0]] = true;
        for(int ind = 1 ; ind<n ; ind++){
            for(int target = 1; target<=sum ; target++){
            bool nottake = prev[ target ];
            bool take = false;
            if(target >= arr[ind]) take = prev[target-arr[ind]];
            curr[target] = nottake || take;
            }
            prev = curr;
        }
        
        
        return prev[sum];
    
    }
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalsum = 0;
        for(int i = 0 ; i<n ; i++) totalsum += arr[i];
        if(totalsum % 2) return false;
        int target = totalsum /2;
        return isSubsetSum(arr , target , n);
        
    }
};