// // TLE
// class Solution {
// public: 
//     int t;
//     int s;

//     int check(int position,int fuel,int index,vector<vector<int>>&stations,map<vector<int>,int>&mp) {
//         if(fuel - (t - position) >= 0) return 0;
//         if(index == stations.size())   return INT_MAX;
//         if(fuel + position < stations[index][0]) return INT_MAX;

//         if(mp.find({index,fuel,position}) != mp.end()) return mp[{index,fuel,position}];

//         int take = INT_MAX; int notTake = INT_MAX;
//         if(stations[index][0] - position <= fuel) {
//             int temp = check(stations[index][0],fuel - (stations[index][0] - position) + stations[index][1],index+1,stations,mp);
//             if(temp != INT_MAX) {
//                 take = 1 + temp;
//             }
//         }
//         notTake = check(position,fuel,index+1,stations,mp);

//         return mp[{index,fuel,position}] = min(take,notTake);
//     }


//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         t = target; s = startFuel;map<vector<int>,int>mp;
//         int ans = check(0,s,0,stations,mp);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };


// class Solution {
// public: 
//     int t;

//     int check(map<pair<int,int>,int>&dp,vector<vector<int>>&stations,int index,int fuel) {
//         if (fuel >= t) return 0; 
//         if (index == stations.size()) return INT_MAX;

//         pair<int, int> state = {index, fuel};
//         if (dp.find(state) != dp.end()) return dp[state];

//         int notTake = check(dp,stations,index+1,fuel);
//         int take = INT_MAX;
//         if(fuel >= stations[index][0]) {
//             int temp = check(dp,stations,index+1,fuel + stations[index][1]);
//             if(temp != INT_MAX) take = 1 + temp;
//         }
//         return dp[state] = min(take,notTake);
//     }

//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         t = target;
//         map<pair<int,int>,int>dp;
//         int ans =  check(dp,stations,0,startFuel);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

#define ll long long
class Solution {
public: 

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        ll n = stations.size();
        vector<ll>dp(n+1);
        dp[0] = startFuel;
        for(ll i = 0;i < n;i++) {
            for(ll j = i;j >= 0;j--) {
                if(dp[j] >= stations[i][0]) {
                    dp[j+1] = max(dp[j+1],dp[j] + stations[i][1]);
                }
            }
        }

        for (ll i = 0; i <= n; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
};
