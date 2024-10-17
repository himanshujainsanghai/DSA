class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) {
            return 0;
        }
        vector<int> vis;
        while (num > 0) {
            vis.push_back(num % 10);
            num /= 10;
        }
        reverse(vis.begin(), vis.end());
        int maxi = 0;
        int maxInd = -1, swapi = -1, swapj = -1;
        for (int i = vis.size() - 1; i >= 0; i--) {
            if (vis[i] > maxi) {
                maxi = vis[i];
                maxInd = i;
            }
            if (vis[i] < maxi) {
                swapi = i;
                swapj = maxInd;
            }
        }
        if (swapi != -1) {
            swap(vis[swapi], vis[swapj]);
        }
        int ans=0;
        for(int i=0 ; i<vis.size() ; i++){
            ans = ans*10 + vis[i];
        }

        return ans;
    }
};