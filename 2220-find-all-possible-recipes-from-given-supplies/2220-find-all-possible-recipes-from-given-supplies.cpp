class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,vector<vector<string>>&  ingredients,vector<string>& supplies) {
        // int n = recipes.size();
        // vector<string> result;

        // unordered_set<string> st(begin(supplies), end(supplies));

        // vector<bool> cooked(n, false);

        // int count = n;
        // while (count--){

        //     for (int j = 0; j < n; j++) {
        //         if (cooked[j]) {
        //             continue;
        //         }

        //         bool banpaega = true;
        //         for (int k = 0; k < ingredients[j].size(); k++) {
        //             if (!st.count(ingredients[j][k])) {
        //                 banpaega = false;
        //                 break;
        //             }
        //         }

        //         if (banpaega) {
        //             st.insert(recipes[j]);
        //             result.push_back(recipes[j]);
        //             cooked[j] = true;
        //         }
        //     }
        // }
        // return result;
        
        // optimal code 
        int n = recipes.size();
        vector<int> indegree(n , 0);
        unordered_set<string> st(begin(supplies) , end(supplies));
        unordered_map<string , vector<int>> adj;

        for(int i=0 ; i<n ; i++){
            for(string& str:ingredients[i]){
                if(!st.count(str)){
                    adj[str].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> que;
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0) que.push(i);
        }

        vector<string> ans;

        while(!que.empty()){
            int ind = que.front();
            que.pop();
            string recipe = recipes[ind];
            ans.push_back(recipe);

            for(auto &ngbr:adj[recipe]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) que.push(ngbr);
            }

        }

        return ans;



    }
};