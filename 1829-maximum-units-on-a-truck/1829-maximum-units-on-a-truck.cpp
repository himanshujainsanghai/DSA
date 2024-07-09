// class Solution {
// public:
//     static bool comp(vector<int> a, vector<int> b) {
//         // return (a.numberOfUnitsPerBox/a.numberOfBoxes >
//         // b.numberOfUnitsPerBox/b.numberOfBoxes); return (double)(a[1]/a[0] >
//         // b[1]/b[0]);
//         return a[1] > b[1];
//     }
//     int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
//         sort(boxTypes.begin(), boxTypes.end(), comp);
//         // int totalVal =0 ;
//         // for(int i =0 ; i<boxTypes.size() ; i++){
//         //     if(boxTypes[i][0] <= truckSize){
//         //         totalVal +=  boxTypes[i][0] * boxTypes[i][1] ;
//         //         truckSize -= boxTypes[i][0];
//         //     }
//         //     else{
//         //         totalVal += (truckSize) * boxTypes[i][1];
//         //         break;
//         //     }
//         // }
//         // return totalVal;
//         int totalUnits = 0;
//         for (int i = 0; i < boxTypes.size(); i++) {
//             if (truckSize <= 0)
//                 break; // If the truck is already full, break the loop

//             int boxesToTake = min(truckSize, boxTypes[i][0]);
//             totalUnits += boxesToTake * boxTypes[i][1];
//             truckSize -= boxesToTake;
//         }
//         return totalUnits;
//     }
// };
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Sort the boxTypes array based on the number of units per box in descending order
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    
    int total_units = 0;
    for (const auto& box : boxTypes) {
        int numberOfBoxes = box[0];
        int unitsPerBox = box[1];
        
        if (truckSize > 0) {
            int boxes_to_take = min(truckSize, numberOfBoxes);
            total_units += boxes_to_take * unitsPerBox;
            truckSize -= boxes_to_take;
        } else {
            break;
        }
    }
    
    return total_units;
}
};