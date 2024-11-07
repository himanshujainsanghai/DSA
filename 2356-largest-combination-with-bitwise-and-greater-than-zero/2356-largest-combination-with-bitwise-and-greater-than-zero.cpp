class Solution {
public:
    int largestCombination(vector<int>& candi) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int maxi=0;
        for(int bitpos =0 ; bitpos<24 ; bitpos++){
            int cnt=0;
            for(int &num:candi){
                if((num & (1<<bitpos)) != 0){
                    cnt++;
                }
            }

            maxi = max(maxi , cnt);
        }

        return maxi;
    }
};