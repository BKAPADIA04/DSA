//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        map<int,int>m;
        int n = arr.size();
        int left = 0; int right = 0;
        vector<int>answer;
        while(right < n) {
            if(arr[right] < 0) m[right]++;
            
            if(right - left + 1 < k) right++;
            else if(right - left + 1 == k) {
                if(m.size() > 0) {
                    auto it = m.begin();
                    // cout << it << endl;
                    answer.push_back(arr[it->first]);
                }
                else answer.push_back(0);
                if(m.find(left) != m.end()) m.erase(left);
                left++;
                right++;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
