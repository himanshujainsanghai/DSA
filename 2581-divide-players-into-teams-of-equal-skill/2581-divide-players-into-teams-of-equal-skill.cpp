class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end());
        int n = skill.size();
        if(n==2) return skill[0]*skill[1];
        int i =0 , j = n-1;
        int s = skill[i]+skill[j];
        long long chem = 0;
        while(i<j){
            int sum = skill[i]+skill[j];
            if(sum != s) return -1;
            chem += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        return chem;
        
    }
};