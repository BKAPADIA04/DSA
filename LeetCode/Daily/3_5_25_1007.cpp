class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int>topFreq(7,0), bottomFreq(7,0);
        for(int i = 0;i < n;i++) {
            topFreq[tops[i]]++;
            bottomFreq[bottoms[i]]++;
        }

        int ans = INT_MAX;
        int maxiTop = *max_element(topFreq.begin(),topFreq.end());
        for(int i = 1;i <= 6;i++) {
            if(topFreq[i] != maxiTop) continue;
            int temp = 0; int j;
            for(j = 0;j < n;j++) {
                if(tops[j] != i && bottoms[j] != i) break;
                if(tops[j] != i) temp++;
            }
            if(j == n) ans = min(ans, temp);
        }

        int maxiBottom = *max_element(bottomFreq.begin(),bottomFreq.end());
        for(int i = 1;i <= 6;i++) {
            if(bottomFreq[i] != maxiBottom) continue;
            int temp = 0; int j;
            for(j = 0;j < n;j++) {
                if(tops[j] != i && bottoms[j] != i) break;
                if(bottoms[j] != i) temp++;
            }
            if(j == n) ans = min(ans, temp);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

/*class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mswaps=INT_MAX;
        for(int val=1;val<=6;val++){
            int tSwap=0, bSwap=0;

            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val && bottoms[i]!=val){tSwap=INT_MAX; bSwap=INT_MAX; break;}

                if(tops[i]!=val){tSwap++;}
                if(bottoms[i]!=val){bSwap++;}
            }

            mswaps = min(mswaps, min(tSwap,bSwap));
        }

        return mswaps==INT_MAX?-1:mswaps;
    }
};*/
