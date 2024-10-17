class Solution {
public:
    int maximumSwap(int num) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);        
        if (num == 0) {
            return 0;
        }
        vector<int> vis;
        int nums = abs(num);
        while (nums > 0) {
            vis.push_back(nums % 10);
            nums /= 10;
        }
        reverse(vis.begin(), vis.end());
        int n=vis.size();
        int maxi = vis[n-1];
        int maxInd = n-1, swapi = -1, swapj = -1;
        for (int i = n-2; i >= 0; i--) {
            if (vis[i] > maxi) {
                maxi = vis[i];
                maxInd = i;
            }
            if (vis[i] < maxi) {
                swapi = i;
                swapj = maxInd;
            }
        }
        if (swapi == -1) {
            return num;

        }
        swap(vis[swapi], vis[swapj]);
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans = ans*10 + vis[i];
        }

        return ans;
    }
};