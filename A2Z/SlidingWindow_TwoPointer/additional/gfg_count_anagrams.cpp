//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        // int m = pat.size(); int n = txt.size();
        // vector<int>freq1(26);
        // for(int i = 0;i < m;i++) {
        //     freq1[pat[i]-97]++;
        // }
        
        // int left = 0; int right = 0; int answer = 0;
        // vector<int>freq2(26);
        // while(right < n) {
        //     freq2[txt[right] - 97]++;
            
        //     if(right - left + 1 < m) right++;
            
        //     else if(right - left + 1 == m) {
        //         bool flag = false;
        //         for(int i = 0;i < 26;i++) {
        //             if(freq1[i] != freq2[i]) { flag = true; break; }
        //         }
        //         if(!flag) answer++;
                
        //         freq2[txt[left]-97]--;
        //         left++;
        //         right++;
        //     }
        // }
        // return answer;
        
        int m = pat.size(); int n = txt.size();
        vector<int>freq(26); int counter = 0;
        for(int i = 0;i < m;i++) {
            if(freq[pat[i]-97] == 0) counter++;
            freq[pat[i]-97]++;
        }
        
        int left = 0; int right = 0; int answer = 0;
        while(right < n) {
            freq[txt[right]-97]--;
            
            if(freq[txt[right]-97] == 0) counter--;
            
            if(right - left + 1 < m) right++;
            else if(right - left + 1 == m) {
                if(counter == 0) answer++;
                freq[txt[left]-97]++;
                if(freq[txt[left]-97] == 1) counter++;
                left++; right++;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends