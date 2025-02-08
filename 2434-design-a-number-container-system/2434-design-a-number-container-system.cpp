
// Using Lazy update with priority queue
class NumberContainers {
    unordered_map<int , int > mpp1;
    unordered_map<int  , priority_queue<int , vector<int> , greater<int>>> mpp2;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mpp1[index] = number;
        mpp2[number].push(index);
        
    }
    
    int find(int number) {
        if(mpp2.find(number) == mpp2.end() || mpp2.empty()){
            return -1;
        }
        while(!mpp2[number].empty()){
            int ind = mpp2[number].top();
            if(mpp1[ind] == number){
                return ind;
            }else{
                mpp2[number].pop();
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */