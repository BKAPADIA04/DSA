//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        
        int n = id.size();
        vector<int>days(n+1,-1);
        vector<pair<int,int>>v;
        for(int i = 0;i < n;i++) {
            v.push_back({profit[i],deadline[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int pro = 0; int ans_days = 0;
        
        for(int i = 0;i < n;i++) {
            int index = v[i].second;
            while(index > 0 && days[index] != -1) {
                index--;
            }
            if(index == 0) continue;
            
            days[index] = 1;
            ans_days++;
            pro += v[i].first;
        }
        return {ans_days,pro};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
