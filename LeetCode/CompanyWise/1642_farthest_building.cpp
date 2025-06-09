class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        vector<int>diff(n,0);
        for(int i = 1;i < n;i++) diff[i] = heights[i] - heights[i - 1];
        sort(diff.begin(),diff.end(),greater<int>());
        unordered_map<int,int>freq;
        for(int i = 0;i < ladders;i++) {
            if(diff[i] <= 0) break;
            freq[diff[i]]++;
        }

        int index = 0;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        while(index < n) {
            if(index == (n - 1)) return index;
            if(heights[index + 1] - heights[index] >= 0) {
                int gap = heights[index+1] - heights[index];
                minHeap.push(gap);
                if(minHeap.size() > ladders) {
                    if(bricks >= minHeap.top()) {
                        bricks -= minHeap.top();
                    }
                    else return index;
                    minHeap.pop();
                }
            }
            index++;
        }
        return index;
    }
};
