class Solution {
    private:
    long long func(vector<int>& skill){
        int n = skill.size();
        vector<int> vec(1001 , 0);
        int sum = 0;
        for(int i =0 ; i<n ; i++){
            sum += skill[i];
            vec[skill[i]]++;

        }
        int teams = n/2;
        if(sum % teams != 0) return -1;
        int target = sum/teams;
        long long chem =0 ;
        for(int i =0 ; i<n ; i++){
            int remskill = target - skill[i];
            if(vec[remskill] <= 0) return -1;
            chem += (long long)(skill[i]) * (long long)(remskill);
            vec[remskill] -=1;
        }
        return chem/2;

    }
public:
    long long dividePlayers(vector<int>& skill) {
        // sort(skill.begin() , skill.end());
        // int n = skill.size();
        // if(n==2) return skill[0]*skill[1];
        // int i =0 , j = n-1;
        // int s = skill[i]+skill[j];
        // long long chem = 0;
        // while(i<j){
        //     int sum = skill[i]+skill[j];
        //     if(sum != s) return -1;
        //     chem += (long long)(skill[i]) * (long long)(skill[j]);
        //     i++;
        //     j--;
        // }
        // return chem;
        return func(skill);
        
    }
};