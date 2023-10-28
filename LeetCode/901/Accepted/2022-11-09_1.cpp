class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int* ptr = &prices.back() - 1;
        while(ptr >= &prices.front() && *ptr <= price) {
            ptr--;
            span++;
        }
        return span;
    }
private:
    vector<int> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */