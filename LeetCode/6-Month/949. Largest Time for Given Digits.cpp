class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> cnt(10, 0);
        for (int d : arr) cnt[d]++;

        for (int h1 = 2; h1 >= 0; h1--) {
            if (cnt[h1] == 0) continue;
            cnt[h1]--;

            for (int h2 = (h1 == 2 ? 3 : 9); h2 >= 0; h2--) {
                if (cnt[h2] == 0) continue;
                cnt[h2]--;

                for (int m1 = 5; m1 >= 0; m1--) {
                    if (cnt[m1] == 0) continue;
                    cnt[m1]--;

                    for (int m2 = 9; m2 >= 0; m2--) {
                        if (cnt[m2] == 0) continue;

                        return to_string(h1) + to_string(h2) + ":" +
                               to_string(m1) + to_string(m2);
                    }

                    cnt[m1]++;
                }

                cnt[h2]++;
            }

            cnt[h1]++;
        }

        return "";
    }
};

/*class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> cnt(10, 0);
        for (int d : arr) cnt[d]++;

        for (int h1 = 2; h1 >= 0; h1--) {
            if (cnt[h1] == 0) continue;
            cnt[h1]--;

            for (int h2 = (h1 == 2 ? 3 : 9); h2 >= 0; h2--) {
                if (cnt[h2] == 0) continue;
                cnt[h2]--;

                for (int m1 = 5; m1 >= 0; m1--) {
                    if (cnt[m1] == 0) continue;
                    cnt[m1]--;

                    for (int m2 = 9; m2 >= 0; m2--) {
                        if (cnt[m2] == 0) continue;

                        return to_string(h1) + to_string(h2) + ":" +
                               to_string(m1) + to_string(m2);
                    }

                    cnt[m1]++;
                }

                cnt[h2]++;
            }

            cnt[h1]++;
        }

        return "";
    }
};
*/
