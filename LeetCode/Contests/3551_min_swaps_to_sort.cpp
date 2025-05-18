#define ll long long
class Solution {
public:

    void print(map<pair<ll,ll>,ll>mp) {
        for(auto it : mp) {
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        }
    }

    ll sumDigit(ll num) {
        ll temp = num;
        ll sum = 0;
        while(temp > 0) {
            ll last = temp % 10;
            sum += last;
            temp /= 10;
        }
        return sum;
    }
    
    
    int minSwaps(vector<int>& nums) {
        ll n = nums.size();
        vector<pair<ll,ll>>nums1;
        map<pair<ll,ll>,ll>mp1,mp2;
        unordered_map<ll,pair<ll,ll>>umap;
        for(ll i = 0;i < n;i++) {
            nums1.push_back({sumDigit(nums[i]), nums[i]});
            mp1[{sumDigit(nums[i]), nums[i]}] = i;
            umap[i] = {sumDigit(nums[i]), nums[i]};
        }

        sort(nums1.begin(),nums1.end());
        for(ll i = 0;i < n;i++) {
            mp2[{nums1[i].first, nums1[i].second}] = i;
        }

        // print(mp1);
        // print(mp2);

        int ans = 0;
            
        for(ll i = 0;i < n;i++) {
            ll newPos = mp2[{nums1[i].first, nums1[i].second}];
            ll oldPos = mp1[{nums1[i].first, nums1[i].second}];

            // cout << newPos << " " << oldPos << endl;
            if(newPos == oldPos) continue;
            ans++;
            swap(mp1[{nums1[i].first, nums1[i].second}], mp1[umap[newPos]]);
            swap(umap[oldPos],umap[newPos]);
        }
        return ans;
        
    }
};

/*class Solution {
public:
    int findsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        sort(v.begin(), v.end(), [&](int a, int b) {
            int sumA = findsum(a);
            int sumB = findsum(b);
            if (sumA == sumB) return a < b;
            return sumA < sumB;
        });

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }

        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || v[i] == nums[i]) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = mp[v[j]];
                cycle_size++;
            }

            if (cycle_size > 1) {
                cnt += (cycle_size - 1);
            }
        }

        return cnt;
    }
};©leetcode*/
