#define ll long long
class Solution {
public:
    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        priority_queue<int>maxHeap;
        for(int i = 0;i < n;i++) {
            minHeap.push({capital[i],profits[i]});
        }

        while(k--) {
            while(!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if(maxHeap.size() == 0) break;
            int prof = maxHeap.top();
            w += prof;
            maxHeap.pop();
        }
        return w;
    }
};
