class Solution {
public:
    typedef long long ll;
    bool possible(int n , ll mid , vector<int>& batteries){
        ll target = n*mid;

        for(auto &it:batteries){
            target -= min((ll)it , mid);

            if(target<=0) return true;
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = INT_MAX;
        ll r = 0;

        for(auto &it:batteries){
            l = min(l , (ll)it);
            r += it;
        }

        r = r/n;

        ll result = l;
        while(l<=r){
            ll mid = l + (r-l)/2;

            if(possible(n , mid , batteries)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }


        return result;

    }
};