class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings) , end(meetings));
        int start=0, end=0;
        int daysOff = 0;
        int result =0;
        for(auto &meet:meetings){
            start = meet[0];
            if(start > end){
            daysOff = start-end-1;
            result += daysOff;

            }
            end = max(end , meet[1]);

        }

        if(end < days){
            result += days-end;
        }
        return result;
        
    }
};