class Solution {
    private:
    int func(long long  num , vector<int>& nums , int cnt){
        if(num*num > 100000){
            return cnt;
        }
        int val = num * num;
        if(any_of(nums.begin() , nums.end() , [val](int p){return p==val;})){
            return func(val , nums , cnt+1);
        }

        return cnt;
    }
public:
    int longestSquareStreak(vector<int>& nums) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        
        // sort(nums.begin() , nums.end());
        // int cnt =0;

        // for(int i=0 ; i<nums.size() ; i++){
        //     cnt = max(cnt , func(nums[i], nums , 1));
        // }
        // tabulated version of this -->

        unordered_set<int> st(nums.begin() , nums.end());
        int cnt =0;

        for(auto &num : nums){
            long long curr = num;
            int streak =0;

            while(st.find(curr) != st.end()){
                streak++;

                if(curr*curr >1e5){
                    break;

                }

                curr *= curr;

            }

            cnt = max(cnt , streak);
        }




        // APPROACH 2 --->
        // unordered_map<int , int> mpp;
        // int cnt =0;
        // for(auto num : nums){
        //     int val = (int)sqrt(num);
        //     if(val*val == num && mpp.find(val) != mpp.end()){
        //         mpp[num] = mpp[val] +1;
        //     }else{
        //         mpp[num] = 1;
        //     }

        //     cnt = max(cnt , mpp[num]);
        // }



        return (cnt<2)? -1 : cnt;
    }
};