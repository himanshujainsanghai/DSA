class Solution {
    private:
    int countbits(int num){
        if(num==0) return 0;
        int count =0;
        while(num !=0){
            int temp = num & 1;
            if(temp != 0) count++;

            num >>= 1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int& a , int& b){
            // int ca = countbits(a);
            // int cb = countbits(b);
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);

            if(ca==cb){
                return a<b;
            }
            return ca<cb;
        };
        sort(arr.begin() , arr.end() , lambda);
        return arr;
    }
};