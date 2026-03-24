class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int>odd, even;
        for(int i = 0;i < n;i++) {
            if(nums1[i] & 1) odd.push_back(nums1[i]);
            else even.push_back(nums1[i]);
        }

        sort(odd.begin(), odd.end());

        // odd
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            bool flag = false;
            if(nums1[i] & 1) {
                cnt++; continue;
            }
            auto it = upper_bound(odd.begin(), odd.end(), nums1[i] - 1);
            // cout << *it << " odd" << endl;
            if(it != odd.begin()) flag = true;

            if(flag) cnt++;
        }
        if(cnt == n) return true;

        cnt = 0;
        for(int i = 0;i < n;i++) {
            bool flag = false;
            if(!(nums1[i] & 1)) {
                cnt++; continue;
            }
            // odd.erase(nums1[i]);
            auto it = upper_bound(odd.begin(), odd.end(), nums1[i] - 1);
            // cout << *it << " even" << endl;
            if(it != odd.begin()) flag = true;
            // odd.insert(nums1[i]);
            if(flag) cnt++;
        }
        if(cnt == n) return true;

        return false;
    } 
};
