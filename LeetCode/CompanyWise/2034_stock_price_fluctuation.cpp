class StockPrice {
public:

    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<pair<int,int>>pq;
    multiset<int>ms;
    unordered_map<int,int>umap;

    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if(umap.find(timestamp) == umap.end()) {
            umap[timestamp] = price;
            maxHeap.push(price);
            minHeap.push(price);
            pq.push({timestamp,price});
            ms.insert(price);
        }
        else {
            int lastPrice = umap[timestamp];
            ms.erase(ms.find(lastPrice));
            while(!maxHeap.empty() && ms.find(maxHeap.top()) == ms.end()) {
                maxHeap.pop();
            }
            while(!minHeap.empty() && ms.find(minHeap.top()) == ms.end()) {
                minHeap.pop();
            }
            umap[timestamp] = price;
            maxHeap.push(price);
            minHeap.push(price);
            pq.push({timestamp,price});
            ms.insert(price);
        }
    }
    
    int current() {
        while(!pq.empty()) {
            int timestamp = pq.top().first;
            int price = pq.top().second;
            if(umap[timestamp] == price) return price;
            pq.pop();
        }
        return -1;
    }
    
    int maximum() {
        return maxHeap.top();
    }
    
    int minimum() {
        return minHeap.top();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
