#define ll long long
class Solution {
public:

    unordered_map<char,ll>mp;
    int n;
    int m;
    int counter;
    int sz;
    vector<vector<pair<ll,ll>>>adj;
    vector<vector<unsigned ll>>distance;
    vector<char> original,changed; vector<int> cost;

    void floydwarshall() {
        distance = vector<vector<unsigned ll>>(sz,vector<unsigned ll>(sz,LLONG_MAX));
        for(int i = 0;i < sz;i++) {
            distance[i][i] = 0ll;
        }

        for(ll i = 0;i < m;i++) {
            distance[mp[original[i]]][mp[changed[i]]] = min(distance[mp[original[i]]][mp[changed[i]]], (unsigned ll)cost[i]);
        }

        for(ll k = 0;k < sz;k++) {
            for(ll i = 0;i < sz;i++) {
                for(ll j = 0;j < sz;j++) {
                    if(distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        n = source.size();
        m = original.size();
        counter = 0;
        for(int i = 0;i < n;i++) {
            if(mp.find(source[i]) == mp.end()) {
                mp[source[i]] = counter++;
            }
            
            if(mp.find(target[i]) == mp.end()) {
                mp[target[i]] = counter++;
            }
        }

        for(int i = 0;i < m;i++) {
            if(mp.find(original[i]) == mp.end()) {
                mp[original[i]] = counter++;
            }
            
            if(mp.find(changed[i]) == mp.end()) {
                mp[changed[i]] = counter++;
            }
        }

        sz = mp.size();

        this->original = original;
        this->changed = changed;
        this->cost = cost;
        floydwarshall();

        ll ans = 0ll;
        for(ll i = 0;i < n;i++) {
            if(distance[mp[source[i]]][mp[target[i]]] == LLONG_MAX) return -1ll;
            ans = ans + distance[mp[source[i]]][mp[target[i]]];
        }
        return ans;
    }
};
