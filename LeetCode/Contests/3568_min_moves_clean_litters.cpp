class Solution {
public:

    int m,n;
    int e;
    
    bool isValid(int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    
    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size(); n = classroom[0].size();
        e = energy;
        
        map<pair<int,int>,int>litterCoordMap;
        vector<pair<int,int>>litterCoord;
        int startR = -1; int startC = -1;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(classroom[i][j] == 'S') {
                    startR = i; startC = j;
                }
                else if(classroom[i][j] == 'L') {
                    litterCoordMap[{i,j}] = litterCoord.size();
                    litterCoord.push_back({i,j});
                }
            }
        }

        int numLitter = litterCoord.size();
        if(numLitter == 0) return 0;

        int targetMask = (1 << numLitter) - 1;
        vector<vector<vector<vector<int>>>> dist(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy + 1, vector<int>(targetMask + 1, -1))));

        queue<tuple<int,int,int,int>>q;
        q.push({startR,startC,energy,0});
        dist[startR][startC][energy][0] = 0;

        vector<int>xCoord = {-1,0,1,0};
        vector<int>yCoord = {0,1,0,-1};

        while(!q.empty()) {
            auto [r,c,currEnergy,mask] = q.front();
            q.pop();

            int moves = dist[r][c][currEnergy][mask];
            if(mask == targetMask) return moves;

            for(int i = 0;i < 4;i++) {
                int newX = r + xCoord[i];
                int newY = c + yCoord[i];

                if(isValid(newX,newY) && classroom[newX][newY] != 'X') {
                    if(currEnergy == 0) continue;
                    int newEnergy = currEnergy - 1;
                    int totalMoves = moves + 1;
                    int newMask = mask;

                    char ch = classroom[newX][newY];
                    if(ch == 'L') {
                        int litterIndex = litterCoordMap[{newX,newY}];
                        newMask |= (1 << litterIndex);
                    }

                    if(ch == 'R') newEnergy = e;

                    if(dist[newX][newY][newEnergy][newMask] == -1 || 
                        totalMoves < dist[newX][newY][newEnergy][newMask]) {
                            dist[newX][newY][newEnergy][newMask] = totalMoves;
                            q.push({newX,newY,newEnergy,newMask});
                        }
                }
            }
        }
        return -1;
    }
};
