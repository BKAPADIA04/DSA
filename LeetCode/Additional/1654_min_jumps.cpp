class Solution {
public:
    // to track the forbidden positions
    unordered_map<int,int>m;
    int dp[7001][2];
    int solve(int i,bool back,int a,int b,int x)
    {
        // base case
        if(i == x)return 0;
        // you cannot land on -ve n0.and blocked positions
        if( i < 0 || m.find(i)!= m.end() || i>6000 )
            return 1e9;
        
        
        if(dp[i][back]!=-1)return dp[i][back];
        int forward = 0;
        // either go forward 
        dp[i][back] = 1 + solve(i+a,0,a,b,x);
        //go backward but cannot go consecutively 2 times
        if(!back)
        {
            dp[i][back] = min(dp[i][back],1 + solve(i-b,1,a,b,x));
        }
      
        return dp[i][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        for(int i = 0 ; i<forbidden.size();i++)
            m[forbidden[i]] = 1;
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,a,b,x);
        if(ans > 1e9)return -1;
        return ans;
    }
};

/*class Solution {
public:
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		unordered_set<int> forbi(forbidden.begin(), forbidden.end());
		vector<vector<int>> visited(2,vector<int>(5000));
		// visited array has two states:
		// visited[0][i] means the ith cell was reached from its left hand side jumping forward, 
		// visited[1][i] means the ith cell was reached from its right hand side jumping backward. 
		queue<pair<int,bool>> qu; 
		// true means your last jump was backward jumping, you cannot jump backward in current step.
		// false, otherwise.
		qu.push({0,false});
		visited[0][0] = 1;
		visited[1][0] = 1;
		int ans = 0;
		while(!qu.empty()) {
			int len = qu.size();
			while(len > 0) {
				len--;
				int cur = qu.front().first;
				bool flag = qu.front().second;
				if(cur == x) {
					return ans;
				}
				qu.pop();
				int forward = cur + a;
				int backward = cur - b;
				if(forward < 5000 && visited[0][forward] == 0 && !forbi.count(forward)) {
					qu.push({forward,false});
					visited[0][forward] = 1;
				}
				if(backward >=0 && visited[1][backward] == 0 && !forbi.count(backward) && !flag) {
					qu.push({backward,true});
					visited[1][backward] = 1;
				}
			}
			ans++;
		}
		return -1;
	}
};*/
