#define ll long long
class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        map<string,ll>mp;
        string str;
        ll answer = 0ll;

        for(int i = 0;i < n;i++) {
            int gap = 'z' - words[i][0];
            str.push_back('z');
            for(int j = 1;j < m;j++) {
                int zGap = 'z' - words[i][j];
                if(gap > zGap) {
                    str.push_back((char)('a' + (gap - zGap - 1)));
                }
                else {
                    str.push_back((char)(words[i][j] + gap));
                }
            }
            answer += mp[str];
            mp[str]++;
            str.clear();
        }
        return answer;
    }
};
