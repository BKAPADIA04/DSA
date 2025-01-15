class Solution {
public:

    int countSet(int n) {
        int count = 0;
        int i = 0; int counter = 1;
        while(counter <= n) {
            if(n & counter) count++;
            i++;
            counter = (1 << i);
            cout << count << endl;
        }
        return count; 
    }

    int minimizeXor(int num1, int num2) {
        int set = countSet(num2);

        int answer = 0;
        for(int i = 31; i >= 0 && set > 0;i--) {
            if(num1 & (1 << i)) {
                answer |= (1 << i);
                set--;
            }
        }

        for(int i = 0;i < 32 && set > 0;i++) {
            if(!(num1 & (1 << i))) {
                answer |= (1 << i);
                set--;
            }
        }

        return answer;
    }
};
