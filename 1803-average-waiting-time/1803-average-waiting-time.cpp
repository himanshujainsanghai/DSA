// class Solution {
// public:
//     double averageWaitingTime(vector<vector<int>>& cust) {
//         int n = cust.size();
//         int start = cust[0][0] , time = cust[0][0] + cust[0][1];;
//         double  wt = cust[0][1] ;
//         for(int i =1 ; i< n ; i++){
//             if(cust[i][0] <= time){
//                 time += cust[i][1];
//                 wt += time - cust[i][0]; 

//             }
//             else{
//                 wt += cust[i][1]; 
//             }
//         }
//         return (double)(wt/n);
        
//     }
// };

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int n = cust.size();
        long long currentTime = 0, totalWaitingTime = 0;
        
        for (int i = 0; i < n; i++) {
            int arrivalTime = cust[i][0];
            int orderTime = cust[i][1];
            
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            
            currentTime += orderTime;
            totalWaitingTime += (currentTime - arrivalTime);
        }
        
        return (double)totalWaitingTime / n;
    }
};
