class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;
        if(a>0){
            pq.push({a , 'a'});
        }
        if(b>0){
            pq.push({b , 'b'});
        }
        if(c>0){
            pq.push({c ,'c'});
        }
        string ans = "";
        if(pq.empty()) return ans;
        while(!pq.empty()){
            int curr = pq.top().first;
            char currchar = pq.top().second;
            pq.pop();
            if(ans.size() >=2 && ans[ans.size()-1]==currchar && ans[ans.size()-2]==currchar ){
                if(pq.empty()){
                    break;
                }
                int num = pq.top().first;
                char newchar =pq.top().second;
                pq.pop();
                ans.push_back(newchar);
                if(num-1 >0){
                    pq.push({num-1 , newchar});
                }
            }
            else{
                curr--;
                ans.push_back(currchar);
            }


            if(curr >0){
                pq.push({curr , currchar});
            }
        }
        return ans;
    }
};