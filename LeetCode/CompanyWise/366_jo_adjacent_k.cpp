#include <bits/stdc++.h>
using namespace std;

    int minMoves(string &s, int k, char ch) {
        int n = s.size();
        vector<int> index;
        for(int i = 0;i < n;i++) {
            if(s[i] == ch) {
                index.push_back(i);
            }
        }
        vector<long long> prefix;
        long long sum = 0;
        for(int i = 0;i < index.size();i++) {
            sum += index[i];
            prefix.push_back(sum);
        }

        long long ans = INT_MAX;
        long long radius = (k & 1) ? k/2 : (k-2)/2;
        //make a window of size k
        //move the window
        for(int i = 0,j = k-1;j < index.size();i++,j++) {
            long long cost = 0;
            if(k & 1) {
                long long pivot = (i+j)/2;
                long long right = prefix[j] - prefix[pivot];
                long long left = (pivot > 0 ? prefix[pivot-1] : 0) - (i>0 ? prefix[i-1] : 0);
                long long save = (radius+1)*radius;
                cost = right - left - save;
            }
            else {
                long long pivot = (i+j)/2;
                long long right = prefix[j] - prefix[pivot];
                long long left = (pivot > 0 ? prefix[pivot-1] : 0) - (i>0 ? prefix[i-1] : 0);
                long long save = (radius+1)*radius + (radius+1);
                cost = right - left - index[pivot] - save;
            }
            ans = min(ans,cost);
        }
        return ans;
    }


int main() {
  int n; cin >> n;
  char ch; cin >> ch;
  string s; cin >> s;
  
  
  int count = 0;
  for(int i = 0;i < n;i++) {
    if(s[i] == ch) count++;
  }
  
  cout << minMoves(s,count,ch) << endl;
  return 0;
  
}
