class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int , int> map1;                                
        // unordered_map<int , int> map2;
        // for(int i=0 ; i<n ; i++){
        //     map2[nums[i]]++;
        // }
        
        // for(int i=0 ; i<n ; i++){
        //     int num = nums[i];
        //     map1[num]++;
        //     map2[num]--;
        //     int n1 = i+1;
        //     int n2 = n-i-1;
        //     if(map1[num]*2 > n1 && map2[num]*2 > n2){
        //         return i;
        //     }
        // }

        // return -1;



        // Approach 2 using Boyce Moore algorithm for majority element
        int n = nums.size();
        int maj=-1;
        int count=0;
        for(int i=0 ; i<n ; i++){
            if(count==0){
                maj=nums[i];
                count=1;

            }
            else if(nums[i] == maj){
                count++;
            }
            else{
                count--;
            }
        }

        int majCount=0;
        for(int& num:nums){
            if(num==maj){
                majCount++;
            }
        }
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == maj){
                cnt++;
            }
            int rem = majCount-cnt;
            int n1 = i+1 ;
            int n2 = n-i-1;

            if(cnt*2 > n1 && rem*2 > n2 ){
                return i;
            }
        }

        return -1;

    }
};