// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord,
//     vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin() , wordList.end());
//         vector<vector<string>> ans;
//         if(st.find(endWord) == st.end()) return ans;
//         queue<vector<string>> q;
//         q.push({beginWord});
//         vector<string> usedlvl;
//         usedlvl.push_back(beginWord);
//         int level = 0;
//         while(!q.empty()){
//             vector<string> vec = q.front();
//             q.pop();
//             if(vec.size() > level){
//                 level++;
//                 for(auto it:usedlvl){
//                     st.erase(it);
//                 }
//                 usedlvl.clear();
//             }
//             string word = vec.back();
//             if(word == endWord){
//                 if(ans.size() == 0){
//                     ans.push_back(vec);
//                 }
//                 else if(ans[0].size() == vec.size()){
//                     ans.push_back(vec);
//                 }
//             }
//             for(int i =0 ; i<word.size() ; i++){
//                 char org = word[i];
//                 for(char ch = 'a' ; ch<='z' ; ch++){
//                     word[i] =ch;
//                     if(st.find(word) != st.end()){
//                         vec.push_back(word);
//                         q.push(vec);
//                         usedlvl.push_back(word);

//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = org;
//             }

//         }
//         return ans;
//     }
// };

class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    int sz;

private:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin() , seq.end());
            ans.push_back(seq);
            reverse(seq.begin() , seq.end());
            return;
        }
        int steps = mpp[word];
        for (int i = 0; i < sz; i++) {
            char org = word[i];
            for(char ch = 'a' ; ch<='z' ; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() &&
                mpp[word] +1 == steps){
                    seq.push_back(word);
                    dfs(word , seq);
                    seq.pop_back();
                }

            }
            word[i] = org;
        }
    }

public:
    vector<vector<string>> findLadders(string beginword, string endword,
                                       vector<string>& wordlist) {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        queue<string> q;
        q.push(beginword);
        b = beginword;
        mpp[beginword] = 1;
        sz = beginword.size();
        st.erase(beginword);
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endword) break;
            for (int i = 0; i < sz; i++) {
                char org = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        if (mpp.find(endword) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endword);
            dfs(endword, seq);
        }
        return ans;
    }
};
