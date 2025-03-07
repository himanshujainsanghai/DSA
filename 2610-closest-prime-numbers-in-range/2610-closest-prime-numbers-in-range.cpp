class Solution {

public:
    bool isPrime(int num){
        if(num==1){
            return false;
        }
        for(int i=2 ; i*i <= num ; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> result = {-1 , -1};
        int mini = INT_MAX;
        vector<int> vis;

        for(int i=left ; i<=right ; i++){
            if(isPrime(i) == true){
                if(!vis.empty() && i-vis.back() <=2){
                    return {vis.back() , i};
                }
                else if(!vis.empty() && i-vis.back() < mini){
                    mini = i-vis.back();
                    result = {vis.back() ,  i};
                }
                vis.push_back(i);
            }
        }

        return result;
        
    }
};