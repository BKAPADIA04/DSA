#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0ll; ll n = bottomLeft.size();
        for(ll i = 0;i < n;i++) {
            ll x1 = bottomLeft[i][0]; ll y1 = bottomLeft[i][1];
            ll x2 = topRight[i][0]; ll y2 = topRight[i][1];

            for(ll j = i+1;j < n;j++) {
                // if(i == j) continue;

                ll x3 = bottomLeft[j][0]; ll y3 = bottomLeft[j][1];
                ll x4 = topRight[j][0]; ll y4 = topRight[j][1];

                if(x3 >= x2 || x4 <= x1 || y4 <= y1 || y3 >= y2) continue;
                ll leftX = max(x1,x3);
                ll leftY = max(y1,y3);

                ll rightX = min(x2,x4);
                ll rightY = min(y2,y4);

                ll side = min(abs(leftX - rightX),abs(leftY - rightY));
                ans = max(ans, side * side);
            }
        }
        return ans;
    }
};
