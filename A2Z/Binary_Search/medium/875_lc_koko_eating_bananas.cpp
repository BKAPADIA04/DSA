#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int timeToEatAllBananas(vector<int>&piles,int h) {
        int n = piles.size();
        long long int req = 0ll;
        for(int i = 0;i < n;i++) {
            req += ceil((piles[i] + h - 1)/h);
        }
        return req;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        int result = h;
        for(int i = 0;i < n;i++) {
            maxi = max(maxi,piles[i]);
        }   
        int low = 1;
        int high = maxi;
        while(low <= high) {
            int mid = (low + high) / 2;
            long long int req = timeToEatAllBananas(piles,mid);
            if((long long int)(req) <= h) {result = mid;high = mid - 1;}
            else { low = mid + 1;}
        }
        return result;
    }
};

int main()
{
    vector<int> v = {805306368,805306368,805306368};
    int h = 1e9;
    Solution s;
    int ans = s.minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}


