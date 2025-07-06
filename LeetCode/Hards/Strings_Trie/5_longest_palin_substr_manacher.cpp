class Solution {
public:
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     // starting from the center and moving towards the boundaries

    //     int start = 0, end = 1;// end = length of the substring
    //     int low,high;

    //     for(int i = 0;i < n;i++) {
    //         // even length substring
    //         low = i - 1;
    //         high = i;
    //         while(low >= 0 && high < n && s[low] == s[high]) {
    //             if(high - low + 1 > end) {
    //                 start = low;
    //                 end = high - low + 1; 
    //             }
    //             low--;
    //             high++;
    //         }

    //         // odd length substring
    //         low = i - 1;
    //         high = i + 1;
    //         while(low >= 0 && high < n && s[low] == s[high]) {
    //             if(high - low + 1 > end) {
    //                 start = low;
    //                 end = high - low + 1; 
    //             }
    //             low--;
    //             high++;
    //         }
    //     }
    //     return s.substr(start,end);
    // }

    vector<int>p;

    string createManacherString(string &s) {
        string str;
        for(auto it : s) {
            str += "#";
            str.push_back(it);
        }
        str += "#";
        return str;
    }

    void createManacherArray(string &str) {
        int l = 0, r = 0;
        int n = str.size();
        p = vector<int>(n,1);

        for(int i = 0;i < n;i++) {
            int mirror = l + r - i;
            if(i < r && mirror >= 0 && mirror < n) {
                p[i] = min(r - i, p[mirror]);
            }

            while((i - p[i] >= 0) && (i + p[i] < n) && (str[i - p[i]] == str[i + p[i]])) {
                p[i]++;
            }

            if(i + p[i] > r) {
                l = i - p[i] + 1;
                r = i + p[i] - 1;
            }
        }
    }

    int getLongest(int index, int odd) {
        int pos = 2 * index + 1 + (odd == 0 ? 1 : 0); // shift 1 for even
        return p[pos]-1;
    }

    bool isPalin(int l, int r) {
        int radii = getLongest((l + r)/2, (l % 2) == (r % 2));
        if(r - l + 1 <= radii) return true;
        return false;
    }

    string longestPalindrome(string s) {
        string str = createManacherString(s);
        createManacherArray(str);
        // cout << str << endl;

        // for(auto it : p) cout << it << " ";
        int answer = 0;
        int index = -1; 
        for(int i = 0;i < s.size();i++) {
            if(getLongest(i,1) > answer) {
                answer = getLongest(i,1);
                index = i;
            }
            if(getLongest(i,0) > answer) {
                answer = getLongest(i,0);
                index = i;
            }
        }

        int start = index - (answer - 1) / 2;
        string ans = s.substr(start, answer);

        return ans;
    }
};
