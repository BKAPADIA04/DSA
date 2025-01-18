//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        queue<pair<int,int>>pq;
        vector<int>dist(100000,INT_MAX);
        pq.push({0,start});
        dist[start] = 0;
        
        while(!pq.empty()) {
            int timer = pq.front().first;
            int node = pq.front().second;
            pq.pop();
            
            // cout << node << " ";
            
            if(node == end) return timer;
            
            for(int i = 0;i < n;i++) {
                int check = (arr[i] * node) % 100000;
                if(timer+1 < dist[check]) 
                { 
                    dist[check] = timer+1; pq.push({timer+1,check});
                    // if(check == end) cout << "ji" << endl;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends