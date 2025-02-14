#define ll long long
class Solution {
public:

    void print(vector<pair<ll,int>>v) {
        for(auto it:v) cout << it.first << " " << it.second << endl;
    }

    ll sum(int num) {
        ll ans = 0;
        int temp = num;
        while(temp > 0) {
            int digit = temp % 10;
            ans += digit;
            temp /= 10;
        }
        return ans;
    }

    static bool comp(pair<ll,int>p1,pair<ll,int>p2) {
        if(p1.first < p2.first) return true;

        if(p1.first == p2.first) return p1.second < p2.second;

        return false;
    }

    int maximumSum(vector<int>& nums) {
        ll n = nums.size();
        vector<pair<ll,int>>v;
        for(ll i = 0;i < n;i++) {
            ll sumi = sum(nums[i]);
            v.push_back({sumi,nums[i]});
        }

        sort(v.begin(),v.end(),comp);
        
        // print(v);

        ll j = 0; ll ans = -1;
        for(ll i = 1;i < n;i++) {
            if(v[i].first != v[j].first) {
                if(i - j > 1 && i-2 >= 0) {
                    ans = max(ans,1ll * (v[i-1].second + v[i-2].second));
                }
                j = i; 
            }
            // cout << ans << endl;
        }
        if(n > 1)
            if(v[n-1].first == v[n-2].first) ans = max(ans,1ll*(v[n-1].second + v[n-2].second));
        return ans;
    }
};

/*
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result = -1;
        // Array to map digit sums to the largest element with that sum
        // (82 to cover all possible sums from 0 to 81)
        int digitMapping[82] = {};

        for (int element : nums) {
            int digitSum = 0;

            // Calculate the digit sum of the current element
            for (int currValue = element; currValue; currValue /= 10) {
                int currDigit = currValue % 10;
                digitSum += currDigit;
            }

            // Check if there is already an element with the same digit sum
            if (digitMapping[digitSum] > 0) {
                // Update the result if the sum of the current and mapped
                // element is greater
                result = max(result, digitMapping[digitSum] + element);
            }

            // Update the mapping to store the larger of the current or previous
            // element for this digit sum
            digitMapping[digitSum] = max(digitMapping[digitSum], element);
        }

        return result;
    }
};
*/
