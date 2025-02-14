// class ProductOfNumbers {
//     private:
//     vector<int> nums;
//     int n;
// public:
//     ProductOfNumbers() {
//         nums.clear();
//         n=0;
//     }
    
//     void add(int num) {
//         if(num == 0){
//             nums = {};
//             n =0;
//         }
//         else{
//             if(nums.empty()){
//                 nums.push_back(num);
//             }
//             else{
//                 nums.push_back(nums[n-1]*num);
//             }
//             n++;
//         }
//     }
    
//     int getProduct(int k) {
//         if(k>n) return 0;
//         else if(k==n) return nums[k-1];
//         else{
//             return nums[n-1]/nums[n-k-1];
//         }
//     }
// };


class ProductOfNumbers {
public:
    vector<int> pre{1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num != 0) {
            pre.push_back(num * pre.back());
        } else {
            pre.clear();
            pre.push_back(1);
        }
    }

    int getProduct(int k) {
        return k < pre.size() ? pre.back() / pre[pre.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */