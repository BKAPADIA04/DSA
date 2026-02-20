class Solution {
public:

    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<int> wallsNeeded;
    vector<vector<int>> infectedRegions;
    vector<unordered_set<int>> threatenedCells;
    vector<int> directions = {-1, 0, 1, 0, -1};

    int rows;
    int cols;

    void exploreRegion(int row, int col) {
        visited[row][col] = true;
      
        // Add current cell to the region (encode position as row * cols + col)
        infectedRegions.back().push_back(row * cols + col);
      
        // Check all 4 adjacent cells
        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + directions[dir];
            int newCol = col + directions[dir + 1];
          
            // Check if new position is within bounds
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    // Continue exploring infected cells
                    exploreRegion(newRow, newCol);
                } else if (grid[newRow][newCol] == 0) {
                    // Found a healthy cell that needs a wall
                    wallsNeeded.back() += 1;
                  
                    // Track this threatened cell (use set to avoid duplicates)
                    threatenedCells.back().insert(newRow * cols + newCol);
                }
            }
        }
    }

    int findMostDangerousRegion() {
        int mostDangerousIdx = 0;
        int maxThreatened = threatenedCells[0].size();
      
        for (int i = 1; i < threatenedCells.size(); ++i) {
            int currentThreatened = threatenedCells[i].size();
            if (currentThreatened > maxThreatened) {
                maxThreatened = currentThreatened;
                mostDangerousIdx = i;
            }
        }
      
        return mostDangerousIdx;
    }

    int containVirus(vector<vector<int>>& isInfected) {
        grid = isInfected;
        rows = grid.size();
        cols = grid[0].size();
        visited.assign(rows, vector<bool>(cols));

        int totalWalls = 0;

        while(true) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    visited[i][j] = false;
                }
            }
          
            // Clear previous iteration's data
            wallsNeeded.clear();
            infectedRegions.clear();
            threatenedCells.clear();

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        // Initialize new region
                        wallsNeeded.push_back(0);
                        infectedRegions.push_back({});
                        threatenedCells.push_back({});
                      
                        // Explore the infected region using DFS
                        exploreRegion(i, j);
                    }
                }
            }

            if (infectedRegions.empty()) {
                break;
            }

            int mostDangerousIdx = findMostDangerousRegion();
            totalWalls += wallsNeeded[mostDangerousIdx];
            for (int regionIdx = 0; regionIdx < infectedRegions.size(); ++regionIdx) {
                if (regionIdx == mostDangerousIdx) {
                    // Quarantine the most dangerous region (mark as -1)
                    for (int encodedPos : infectedRegions[regionIdx]) {
                        int row = encodedPos / cols;
                        int col = encodedPos % cols;
                        grid[row][col] = -1;  // Mark as quarantined
                    }
                } else {
                    // Other regions spread to their threatened cells
                    for (int encodedPos : infectedRegions[regionIdx]) {
                        int row = encodedPos / cols;
                        int col = encodedPos % cols;
                      
                        // Check all 4 adjacent cells
                        for (int dir = 0; dir < 4; ++dir) {
                            int newRow = row + directions[dir];
                            int newCol = col + directions[dir + 1];
                          
                            // Infect healthy adjacent cells
                            if (newRow >= 0 && newRow < rows && 
                                newCol >= 0 && newCol < cols && 
                                grid[newRow][newCol] == 0) {
                                grid[newRow][newCol] = 1;
                            }
                        }
                    }
                }
            }
        }
        return totalWalls;
    }
};
