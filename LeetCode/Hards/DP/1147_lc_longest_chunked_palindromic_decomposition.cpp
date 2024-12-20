class Solution {
public:
// using ull = unsigned long long;
    // ull hash(vector<ull>p,vector<ull>h,int l,int r) {
    //     return (h[r] - h[l-1]) * p[r-l+1];
    // }

    bool check(string text,int start1,int start2,int length) {
        while(length--) {
            if(text[start1++] != text[start2++]) return false;
        }
        return true;
    }

    int longestDecomposition(string text) {
        // using ull = unsigned long long;
        // vector<ull>p(text.size() + 2,0);
        // vector<ull>h(text.size() + 2,0);

        // p[0] = 1;
        // int base = 131;
        // for(int i = 0;i < text.size();i++) {
        //     int character = text[i] - 'a' + 1;
        //     p[i+1] = p[i] * base;
        //     h[i+1] = h[i] * base + character;
        // }
    
        int n = text.size(); int ans = 0;
        int i = 0; int j = n - 1;
        while(i <= j) {
            bool flag = false;
            for(int k = 1; i + k - 1 < j - k + 1;k++){
                if(check(text,i,j-k+1,k)) {
                    cout << "hi" << endl;
                    ans += 2;
                    i += k;
                    j -= k;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                ans++; break;
            }
        }
        return ans;
    }
};