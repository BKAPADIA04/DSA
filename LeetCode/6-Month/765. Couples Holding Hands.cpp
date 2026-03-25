class Solution {
public:

    vector<int>parent, size;
    int n;

    int findParent(int x) {
        if(parent[x] == x) return x;

        return parent[x] = findParent(parent[x]);
    }

    void unionBySz(int x, int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);

        if(ultX == ultY) return;

        if(size[ultX] > size[ultY]) {
            size[ultX] += size[ultY];
            parent[ultY] = ultX;
        }
        else {
            size[ultY] += size[ultX];
            parent[ultX] = ultY;
        }
    }

    int minSwapsCouples(vector<int>& row) {
        n = row.size();
        parent = vector<int>(n/2, 0);
        size = vector<int>(n/2, 1);

        for(int i = 0;i < n/2;i++) {
            parent[i] = i;
        }


        for(int i = 0;i < n;i += 2) {
            int f1 = row[i]/2;
            int f2 = row[i+1]/2;

            unionBySz(f1, f2);
        }
        
        int answer = 0;

        for(int i = 0;i < n/2;i++) {
            if(findParent(i) == i) {
                answer += (size[i] - 1);
            }
        }

        return answer;
    }
};
