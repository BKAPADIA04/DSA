class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        int mod = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_map<int,int>freq;
        for(int i = 0;i < hFences.size();i++) {
            for(int j = i + 1;j < hFences.size();j++) {
                int diff = abs(hFences[i] - hFences[j]);
                freq[diff]++;
            }
        }

        int answer = -1;
        for(int i = 0;i < vFences.size();i++) {
            for(int j = i + 1;j < vFences.size();j++) {
                int diff = abs(vFences[i] - vFences[j]);
                if(freq.find(diff) != freq.end()) {
                    answer = max(answer, diff);
                }
            }
        }

        if(answer == -1) return -1;

        return ((long long)answer % mod * (long long)answer % mod) % mod;
    }
};
