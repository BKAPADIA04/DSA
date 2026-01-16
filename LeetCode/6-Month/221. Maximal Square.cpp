class Solution {
public:

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int>left(n,0),right(n,0);
    //     stack<int>st;
    //     for(int i = 0;i < n;i++) {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
    //         if(st.empty()) left[i] = 0; 
    //         else left[i] = st.top() + 1;
    //         st.push(i);
    //     }  
    //     while(!st.empty()) st.pop();    
    //     for(int i = n-1;i >= 0;i--) {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
    //         if(st.empty()) right[i] = n - 1; 
    //         else right[i] = st.top() - 1;
    //         st.push(i);
    //     }    
    //     while(!st.empty()) st.pop();    

    //     int answer = INT_MIN;
    //     for(int i = 0;i < n;i++) {
    //         // if((right[i] - left[i] + 1) == heights[i])
    //         int mini = min(right[i] - left[i] + 1, heights[i]);
    //         answer = max(answer,mini * mini);
    //     }
    //     return answer;
    // }

    // vector<vector<int>> intMatrix(vector<vector<char>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     vector<vector<int>> answer(n,vector<int>(m,0));
    //     for(int i = 0;i < n;i++) {
    //         for(int j = 0;j < m;j++) {
    //             if(matrix[i][j] == '1') answer[i][j] = 1;
    //         }
    //     }
    //     return answer;
    // }

    // int maximalRectangle(vector<vector<char>>& matrix) {
    //     vector<vector<int>> mat = intMatrix(matrix);
    //     int answer = INT_MIN;
    //     vector<int>heights = mat[0];
    //     answer = max(answer,largestRectangleArea(heights));

    //     for(int i = 1;i < mat.size();i++) {
    //         for(int j = 0;j < mat[0].size();j++) {
    //             if(mat[i][j] == 1) {
    //                 heights[j] = heights[j] + 1;
    //             }
    //             else heights[j] = 0;
    //         }
    //         answer = max(answer,largestRectangleArea(heights));
    //     }
    //     return answer;
    // }

    // int maximalSquare(vector<vector<char>>& matrix) {
    //     return maximalRectangle(matrix);
    // }
    int answer;
    vector<vector<int>>dp;
    int check(vector<vector<char>>& matrix, int i, int j, int m, int n) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        if(matrix[i][j] == '1') {
            int opt1 = check(matrix,i-1,j,m,n);
            int opt2 = check(matrix,i,j-1,m,n);
            int opt3 = check(matrix,i-1,j-1,m,n);
            ans = 1 + min(opt1,min(opt2,opt3));
        }

        answer = max(answer,ans);

        // cout << i << " " << j << " " << ans << " " << answer << endl;

        return dp[i][j] = ans;
        
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        answer = 0;
        dp = vector<vector<int>>(m+1,vector<int>(n+1,0));

        vector<int>prev(n+1),curr(n+1);

        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                if(matrix[i-1][j-1] == '1') {
                    curr[j] = 1 + min(prev[j],min(curr[j-1],prev[j-1]));
                }
                else {
                    curr[j] = 0;
                }

                answer = max(answer,curr[j]);
            }
            prev = curr;
        }
        return answer * answer;
    }
};
