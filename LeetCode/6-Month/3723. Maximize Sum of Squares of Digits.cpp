class Solution {
public:
    string answer;

    string maxSumOfSquares(int num, int sum) {
        answer.clear();
        if(9 * num < sum) return answer;
        int i = 0;
        int tempSum = sum;
        while(i < num) {
            for(int i = 9;i >= 0;i--) {
                if(tempSum >= i) {
                    answer.push_back((char)(i + '0'));
                    tempSum -= i;
                    break;
                }
            }
            i++;
        }
        return answer;
    }
};
