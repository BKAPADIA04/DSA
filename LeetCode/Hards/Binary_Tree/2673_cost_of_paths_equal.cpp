class Solution {
public:

    int N;
    int check(int i, int &answer, vector<int>&cost) {
        if(i > N) return 0;

        int left = check(2 * i,answer,cost);
        int right = check(2 * i + 1,answer,cost);

        answer += abs(right - left);

        return cost[i - 1] + max(left,right);
    }

    int minIncrements(int n, vector<int>& cost) {
        int answer = 0;
        N = n;
        check(1,answer,cost);
        return answer;
    }
};
