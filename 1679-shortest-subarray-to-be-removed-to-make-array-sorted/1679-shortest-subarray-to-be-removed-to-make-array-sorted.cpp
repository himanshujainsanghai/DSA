class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int  j = n-1;
        while(j>0 && arr[j-1] <= arr[j]){
            j--;
        }
        if(j==0) return 0;


        int i=0;
        int res = j;

        while(i<j && (i==0 || (arr[i-1]<=arr[i])) ){

            // if arr[i]>arr[j]
            while(j<n && arr[i] > arr[j]){
                j++;
            }

            // we have found correct jth element such that arr[j]>=arr[i]

            res = min(res ,j-i-1);
            i++;
        }

        return res;
        
    }
};