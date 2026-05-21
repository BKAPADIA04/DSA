class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        unordered_map<int,int>mp1;

        for(int i = 0;i < n;i++) {
            int tmp = arr1[i];
            while(tmp) {
                mp1[tmp]++;
                tmp/=10;
            }
        }

        int ans = 0;

        for(int i = 0;i < m;i++) {
            int tmp = arr2[i];
            int sz = to_string(tmp).size();
            while(tmp) {
                if(mp1.find(tmp) != mp1.end()) {
                    ans = max(ans, sz);
                    break;
                }
                sz--;
                tmp/=10;
            }
        }

        return ans;
    }
};
