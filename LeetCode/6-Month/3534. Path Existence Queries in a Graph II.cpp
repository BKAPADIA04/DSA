class Solution {
public:

    int customUpperBound(vector<pair<int,int>>&arr, int limit) {
        int n = arr.size();
        int low = 0; int high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(arr[mid].first <= limit) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr;
        for(int i = 0;i < n;i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        vector<int>nodeToIdx(n);
        for(int i = 0;i < n;i++) {
            nodeToIdx[arr[i].second] = i;
        }

        int rows = n;
        int cols = log2(n) + 1;
        vector<vector<int>>ancestorTable(rows, vector<int>(cols, 0));
        for(int i = 0;i < n;i++) {
            int farthestHop = customUpperBound(arr, arr[i].first + maxDiff);
            ancestorTable[i][0] = farthestHop;
        }

        for(int j = 1;j < cols;j++) {
            for(int node = 0;node < n;node++) {
                ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }

        vector<int>answer;
        for(int i = 0;i < (int)queries.size();i++) {
            int u = queries[i][0]; int v = queries[i][1];
            int a = nodeToIdx[u];
            int b = nodeToIdx[v];
            if(a == b) {
                answer.push_back(0);
                continue;
            }

            if(a > b) {
                swap(a, b);
            }

            int curr  = a;
            int jumps = 0;

            for(int j = cols-1; j >= 0; j--) { //log(n)
                if(ancestorTable[curr][j] < b) {
                    curr = ancestorTable[curr][j];
                    jumps += (1 << j); //pow(2, j)
                }
            }

            if(ancestorTable[curr][0] >= b) {
                answer.push_back(jumps+1);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};
