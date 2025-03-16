class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& ranks, int cars , ll midTime){
        ll carsFixed = 0;
        for(int i=0 ;i<ranks.size() ; i++){
            carsFixed += sqrt(midTime/ranks[i]);
        }
        return carsFixed >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1;
        int maxi = *max_element(ranks.begin() , ranks.end());
        ll r = 1ll * maxi * cars *cars;

        ll result = -1;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(isPossible(ranks , cars , mid)==true){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
        
    }
};