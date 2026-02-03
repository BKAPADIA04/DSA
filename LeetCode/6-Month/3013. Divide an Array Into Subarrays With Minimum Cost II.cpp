#define ll long long
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n = nums.size();
        set<pair<ll,ll>>kMin;
        set<pair<ll,ll>>remaining;

        ll i = 1ll;
        ll sum = 0ll;
        while(i - (ll)dist < 1ll) {
            kMin.insert({(ll)nums[i], i});
            sum += (ll)nums[i];
            if(kMin.size() > k - 1) {
                pair<ll,ll>remove = *kMin.rbegin();
                sum -= (ll)remove.first;
                kMin.erase(remove);
                remaining.insert(remove);
            }
            i++;
        }

        ll res = LLONG_MAX;
        while(i < n) {
            kMin.insert({(ll)nums[i], i});
            sum += (ll)nums[i];
            if(kMin.size() > k - 1) {
                pair<ll,ll>remove = *kMin.rbegin();
                sum -= (ll)remove.first;
                kMin.erase(remove);
                remaining.insert(remove);
            }

            res = min(res, sum);

            pair<ll,ll>searchToRemove = {nums[i - (ll)dist], i - (ll)dist};
            if(kMin.count(searchToRemove) > 0) {
                kMin.erase(searchToRemove);
                sum -= searchToRemove.first;
                if(remaining.size() > 0) {
                    pair<ll,ll>insertIntoKMin = *remaining.begin();
                    sum += insertIntoKMin.first;
                    kMin.insert(insertIntoKMin);
                    remaining.erase(insertIntoKMin);
                }
            }
            else {
                remaining.erase(searchToRemove);
            }

            i++;
        }

        return (ll)nums[0] + res;
    }
};
