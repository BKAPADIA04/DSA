class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int>preSumH(n+1);
        vector<int>preSumV(n+1);

        set<pair<int,int>>st;

        for(int i = 1;i <= n;i++) {
            int h = 0; int v = 0;
            if(s[i-1] == 'D') v = -1;
            else if(s[i-1] == 'U') v = 1;
            else if(s[i-1] == 'L') h = -1;
            else h = 1;

            preSumH[i] = preSumH[i-1] + h;
            preSumV[i] = preSumV[i-1] + v;
        }

        // for(auto it : preSumH) cout << it << " "; cout << endl;
        // for(auto it : preSumV) cout << it << " "; cout << endl;

        for(int i = k;i <= n;i++) {
            int preX = preSumH[i-k];
            int preY = preSumV[i-k];
            int postH = preSumH[n] - preSumH[i];
            int postV = preSumV[n] - preSumV[i];

            int posX = preX + postH;
            int posY = preY + postV;

            // cout << posX << " " << posY << endl;

            st.insert({posX, posY});
        }

        return st.size();
    }
};
