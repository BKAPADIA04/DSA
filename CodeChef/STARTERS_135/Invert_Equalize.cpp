#include <bits/stdc++.h>
#include <iostream>
using namespace std; 
#define vt vector
#define pb push_back
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }

int main() {
	// your code goes here
	int t;
	cin >> t;
    vt <int> ans;
	while(t--) {
	    int n; cin >> n;
	    string str; cin >> str;
	    // for everything to zero
        // counting number of substrings of all 1
        int count_1 = 0;
        int j = 0; int k = 0;
        for(int i = 0;i < n;i++) {
            if(str[i] == '1') {
                j = i; k = i;
                while(str[k] != '0' && k < n) {
                    k++;
                }
                j = k; i = k; count_1++;
            }
        }
        // for everything to one
        // counting number of substrings of all 0
        int count_0 = 0;
        for(int i = 0;i < n;i++) {
            if(str[i] == '0') {
                j = i; k = i;
                while(str[k] != '1' && k < n) {
                    k++;
                }
                j = k; i = k; count_0++;
            }
        }
        ans.pb(min(count_0,count_1));
	}
    print(ans);
}