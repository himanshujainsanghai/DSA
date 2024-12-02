// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         vector<string> vis;
//         for(int i=0 ; i<sentence.size() ; i++){
//             string temp ="";
//             if(sentence[i] !=' '){
//                 temp.push_back(sentence[i]);
//             }
//             else{
//                 if(temp.size()>0){
//                     vis.push_back(temp);
//                 }
//             }
//         }
//         int n = searchWord.size();
//         for(int i=0 ; i<vis.size() ; i++){
//             if(vis[i].size() < n){
//                 continue;
//             }

//             bool fl = true;
//             for(int j=0 ; j<vis[i].size() ; j++){
//                 if(j<n && vis[i][j] != searchWord[j]){
//                     fl = false;
//                     break;
//                 }
//             }

//             if(fl){
//                 return i+1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1; // To track the word's position (1-based index)
        int n = searchWord.size(); // Length of the searchWord
        int i = 0; // Pointer for traversing the sentence

        while (i < sentence.size()) {
            // Start of a word
            int start = i;
            while (i < sentence.size() && sentence[i] != ' ') {
                i++;
            }
            // Extract the current word
            string word = sentence.substr(start, i - start);

            // Check if searchWord is a prefix
            if (word.size() >= n && word.substr(0, n) == searchWord) {
                return wordIndex;
            }

            // Move to the next word
            wordIndex++;
            i++; // Skip the space
        }

        // If no word is a prefix
        return -1;
    }
};
