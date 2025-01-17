class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = derived.size();
        // vector<int> org(n , 0);
        // // case 1 org[0] = 0;
        // for(int i=0 ; i<n-1 ; i++){
        //     org[i+1] = org[i]^derived[i];
        // }
        // if(org[n-1]^derived[n-1] == org[0]){
        //     return true;
        // }

        // // org[0] = 1;
        // // for(int i=0 ; i<n-1 ; i++){
        // //     org[i+1] = org[i]^derived[i];
        // // }
        // // if(org[n-1]^derived[n-1] == org[0]){
        // //     return true;
        // // }
        

        // return false;

        // another Approach xor of all elements in derived is 0 if valid else no original array possible
        int val = 0;
        for(int i=0 ; i<n ; i++){
            val ^= derived[i];
        } 
        if(val == 0) return true;
        return false;
    }
};