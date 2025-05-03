class Solution {
public:

    int check(string &num, int i){
        for(int j = i-1; j >= 0; j--){
            int t = (num[i] - '0') + (num[j] - '0')*10;
            if(t % 25 == 0) return num.size() - j - 2;
        }
        return num.size();
    }

    int minimumOperations(string num) {
        int n = num.size(), ans = n, i;
        for(i = n-1; i >= 0 && num[i] != '0'; i--); //iterate untill '0' is found
        if(i >= 0) ans = min(n - 1, check(num, i));
        for(i = n-1; i >= 0 && num[i] != '5'; i--); //iterate untill '5' is found
        return min(ans, check(num, i));
    }
};

/*class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length(), ans = n - 1;
        if (num.find('0') == string::npos) ans = n;

        // 00 25 50 75
        for (int i = n - 1; i > 0; i--) {
            if (num[i] == '0' || num[i] == '5') {
                for (int j = i - 1; j >= 0; j--) {
                    if (((num[j] == '0' || num[j] == '5') && num[i] == '0') || ((num[j] == '2' || num[j] == '7') && num[i] == '5')) {
                        ans = min(ans, (n - j - 2));
                    }
                }
            }
        }
        return ans;
    }
};*/
