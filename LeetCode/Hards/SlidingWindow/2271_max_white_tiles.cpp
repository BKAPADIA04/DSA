class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int left = 0; int right = 0;
        int n = tiles.size();
        int covered = 0; int maxi = 0;
        while(left < n) {
            while(right < n && (tiles[right][1] - tiles[left][0] + 1 <= carpetLen)) {
                covered += (tiles[right][1] - tiles[right][0] + 1);
                right++;
            }

            if(right < n && tiles[left][0] + carpetLen > tiles[right][0]) {
                maxi = max(maxi,covered + tiles[left][0] + carpetLen - tiles[right][0]);
            }
            else {
                maxi = max(maxi,covered);
            }
            covered -= tiles[left][1] - tiles[left][0] + 1;
            left++;
        }
        return maxi;
    }
};
