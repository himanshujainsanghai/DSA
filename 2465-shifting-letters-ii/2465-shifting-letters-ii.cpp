// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         ios::sync_with_stdio(false); // Disable synchronization with C I/O
//         cin.tie(NULL);               // Untie cin from cout
//         cout.tie(NULL);
//         int n = s.size();
//         vector<int> vis(n , 0);
//         int l = 0 , r = 0 , val = 0;
//         for(auto it:shifts){
//             l = it[0];
//             r = it[1];
//             // val = (it[2]==1)? 1 : -1;

//             // vis[l] += val;
//             // if(r+1 <n){
//             //     vis[r+1] -= val;
//             // }
//             if(it[2] ==1){
//                 vis[l] += 1;
//                 if(r+1 <n){
//                 vis[r+1] -= 1;
//                 }
//             }
//             else{
//                 vis[l] -= 1;
//                 if(r+1<n){
//                     vis[r+1] += 1; 
//                 }
//             }

//         }

//         int cumsum = 0;
//         for(int i=0 ; i<n ; i++){
//             cumsum += vis[i];
//             int shift = cumsum%26;
//             if(shift<0) shift += 26;

//             s[i] = ((s[i]-'a' + shift)%26) + 'a';

//         }
//         return s;
//     }
// };


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> hist(s.size(), 0);
        for(const auto& shift : shifts)
        {
            const int direction = 2*shift[2] - 1;
            hist[shift[0]] += direction;
            int end = shift[1] + 1;
            if(end < hist.size())
                hist[end] += -direction;
        }

        int letter_direction = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            letter_direction += hist[i];
            //cout << i << " "<< hist[i] <<" " << letter_direction<<endl;

            int letter = ((int)s[i] - 'a' + letter_direction)%26;
            if(letter < 0)
                s[i] = 'z' + letter + 1;
            else
                s[i] = 'a' + letter;
        }
        return s;
    }
};