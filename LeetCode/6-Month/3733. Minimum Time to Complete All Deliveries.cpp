typedef long long ll;
class Solution {
public:
    ll lcm(ll a, ll b){
        ll val=a/gcd(a,b);
        return val*b;
    }
    bool candeliver(ll mid,vector<int>& d, vector<int>& r){
        ll both=mid/lcm(r[0],r[1]);
        ll first=mid-mid/r[0];
        ll second=mid-mid/r[1];
        ll avail=mid-both;
        //ll total=first+second-(mid)+both;

        if(first<d[0] || second<d[1])return false;
        return avail>=d[0]+d[1];
    }
    
    long long minimumTime(vector<int>& d, vector<int>& r) {
      ll low=0,high=2e10,ans=-1;
       while(low<=high){
        ll mid=low+(high-low)/2;
           if(candeliver(mid,d,r)){
               ans=mid;
               high=mid-1;
           }
           else low=mid+1;
       }
        return ans;
    }
};
