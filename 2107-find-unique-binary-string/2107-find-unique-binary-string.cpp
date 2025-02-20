class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i=0 ; i<n ; i++){
            char ch = (nums[i][i] == '0'? '1' :'0');
            ans += ch;
        }
        return ans;
    }
};