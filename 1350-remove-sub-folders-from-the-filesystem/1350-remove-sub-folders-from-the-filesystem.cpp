class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        // unordered_set<string> st(folder.begin() , folder.end());
        // vector<string> ans;

        // for(auto& curr : folder){
        //     string temp = curr;
        //     bool flag = false;

        //     while(!curr.empty()){
        //         size_t ind = curr.find_last_of('/');
        //         curr = curr.substr(0 , ind);

        //         if(st.find(curr) != st.end()){
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if(!flag){
        //         ans.push_back(temp);
        //     }

        // }

        // return ans;


        // approach 2

        sort(folder.begin() , folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1 ; i<folder.size() ; i++){
            string curr = folder[i];
            string lastfolder = ans.back();
            lastfolder += '/';
            if(curr.find(lastfolder) != 0){
                ans.push_back(curr);
            }
        }
        return ans;
        
    }
};