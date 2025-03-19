//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:

    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int>lru;
        int answer = 0;
        for(int i = 0;i < N;i++) {
            auto it = find(lru.begin(),lru.end(),pages[i]);
            if(it == lru.end()) {
                if(lru.size() == C) lru.erase(lru.begin());
                answer++;
            }
            else {
                lru.erase(it);
            }
            lru.push_back(pages[i]);
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
