// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
//         vector<vector<int>> arr;
//         int i =0  ;
//         const int n = inter.size();
//         while(i < n && inter[i][1] < newInter[0]){
//             arr.push_back(inter[i++]);
//         }
//         // middle part
//         while(i<n && inter[i][0] <= newInter[1]){
//             newInter[0] = min(newInter[0] , inter[i][0]);
//             newInter[1] = max(newInter[1]  , inter[i][1]);
//             i++;
//         }
//         arr.push_back(newInter);
//         while(i<n){
//             arr.push_back(inter[i++]);
//             // i++;
//         }
//         return arr;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        int n = intervals.size();

        for(int i = 0; i < n; i++){

            if(newInterval[0] > intervals[i][1]){
                res.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                newInterval = intervals[i];
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        res.push_back(newInterval);

        return res;
    }
};