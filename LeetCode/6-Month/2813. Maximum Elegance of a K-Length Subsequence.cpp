#define ll long long
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(), items.end(), greater<vector<int>>());

        unordered_set<int>category;
        priority_queue<int,vector<int>,greater<int>>pq; // duplicates
        ll sum = 0ll; ll distincts = 0ll;

        for(int i = 0;i < k;i++) {
            sum += items[i][0];

            if(category.find(items[i][1]) == category.end()) {
                category.insert(items[i][1]);
                distincts++;
            }
            else {
                pq.push(items[i][0]);
            }
        }

        ll answer = sum + distincts * distincts;
        for(ll i = k;i < n;i++) {
            if(category.find(items[i][1]) != category.end()) continue;

            if(!pq.empty()) {
                sum -= pq.top();
                pq.pop();
                sum += items[i][0];
                category.insert(items[i][1]);
                distincts++;

                answer = max(answer, sum + distincts * distincts);
            }
        }

        return answer;
    }
};
