class StockSpanner {
private:
 std::deque<std::pair<int, int>> que;
public:
    StockSpanner() {
        
    }    
    int next(int price) {
        int span=1;
        //monotic decreasing
        while(!que.empty()&&que.back().first<=price){
            span+=que.back().second;
            que.pop_back();
        }
        que.push_back({price,span});
        return span;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */