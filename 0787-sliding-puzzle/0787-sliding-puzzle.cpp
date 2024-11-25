class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string start = "";
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<3 ; j++){
                start += to_string(board[i][j]);
            }
        }


        string target = "123450";
        if(start == target){
            return 0;
        }
        unordered_map<int , vector<int>> mpp;
        mpp[0]={1,3};
        mpp[1]={0,2,4};
        mpp[2]={1,5};
        mpp[3]={0,4};
        mpp[4]={3,1,5};
        mpp[5]={2,4};


        unordered_set<string> st;
        st.insert(start);
        queue<string> que;
        que.push(start);
        int level = 0;

        while(!que.empty()){
            int n = que.size();

            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == target){
                    return level;
                }

                int index = curr.find('0');
                for(int ind:mpp[index]){
                    string newstate = curr;
                    swap(newstate[index] , newstate[ind]);
                    if(st.find(newstate) == st.end()){
                        st.insert(newstate);
                        que.push(newstate);
                    }
                }

            }

            level++;
        }
        

        return -1;
    }
};