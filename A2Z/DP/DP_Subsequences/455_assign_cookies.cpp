class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int m = g.size(); int n = s.size();
        int i = 0; int j = 0;
        
        int answer = 0;
        while(i < m && j < n) {
            if(s[j] >= g[i]) {
                answer++; i++;
            }
            j++;
        }
        return answer;
    }
};