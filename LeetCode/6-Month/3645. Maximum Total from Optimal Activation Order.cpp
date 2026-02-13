#define ll long long

class Solution {
public:

    static bool comparator(pair<ll,ll>&A, pair<ll,ll>&B) {
        if(A.first == B.first) return A.second > B.second;
        return A.first < B.first;
    }

    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<pair<ll,ll>>nums;
        ll n = value.size();
        for(ll i = 0;i < n;i++) {
            nums.push_back({limit[i], value[i]});
        }

        sort(nums.begin(), nums.end(), comparator);

        // for(auto it : nums) cout << it.first << " " << it.second << endl;

        ll active = 0ll; ll inactive = 0ll;
        ll answer = 0ll;
        vector<bool>wasActive(n, false);

        ll i = 0ll; ll j = 0ll;
        while(i < n) {
            if(active >= nums[i].first) break;
            answer += (ll)nums[i].second;
            active++; 
            wasActive[i] = true;
            ll tmp = active;
            
            while(j <= i && tmp >= nums[j].first) {
                if(wasActive[j]) { active--; wasActive[j] = false; }
                j++;
            }
            i++;
            while(i < n && tmp >= nums[i].first) {
                i++;
            }
        }

        return answer;
    }
};

/*class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int, priority_queue<int>> umap;

        long long ans = 0;

        int n = value.size();

        for (int i = 0; i < n; i++) {
            umap[limit[i]].push(value[i]);
        }

        for (auto &[lim, pq]: umap) {
            for (int i = 0; i < lim && !pq.empty(); i++) {
                ans += pq.top();
                pq.pop();
            }
        }


        return ans;
    }
};*/
