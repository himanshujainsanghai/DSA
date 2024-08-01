// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin() , wordList.end());
//         if(st.find(endWord) == st.end()) return 0;
//         st.erase(beginWord);
//         queue<pair<string , int>> q;
//         q.push({beginWord  , 1});
//         while(!q.empty()){
//             string word = q.front().first;
//             int steps = q.front().second;
//             q.pop();
//             if(word == endWord) return steps;
//             for(int i =0 ; i<word.size() ; i++){
//                 char org = word[i];
//                 for(char ch ='a' ; ch<='z' ; ch++){
//                     word[i] = ch;
//                     if(st.find(word) != st.end()){
//                         st.erase(word);
//                         q.push({word , steps+1});
//                     }

//                 } 
//                 word[i] = org;
//             }
//         }
//         return 0;
        
//     }
// };


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_set<string> beginSet, endSet, tempSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int steps = 1;

        while(!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set to optimize the search
            if(beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            tempSet.clear();
            for(string word : beginSet) {
                for(int i = 0; i < word.size(); i++) {
                    char org = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(endSet.find(word) != endSet.end()) {
                            return steps + 1;
                        }
                        if(wordSet.find(word) != wordSet.end()) {
                            tempSet.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = org;
                }
            }

            swap(beginSet, tempSet);
            steps++;
        }

        return 0;
    }
};
