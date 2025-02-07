class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>m1,m2;
        int n = queries.size();
        vector<int>answer(n,0);
        for(int i = 0;i < n;i++) {
            int ball = queries[i][0]; int color = queries[i][1];
            if(m1.find(ball) != m1.end()) {
                int c = m1[ball];
                m2[c]--;
                if(m2[c] == 0) m2.erase(c);
            }
            m1[ball] = color;
            m2[color]++;
            answer[i] = m2.size();
        }
        return answer;
    }
};
