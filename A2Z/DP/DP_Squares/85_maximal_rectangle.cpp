class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0),right(n,0);
        stack<int>st;
        for(int i = 0;i < n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) left[i] = 0; 
            else left[i] = st.top() + 1;
            st.push(i);
        }  
        while(!st.empty()) st.pop();    
        for(int i = n-1;i >= 0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) right[i] = n - 1; 
            else right[i] = st.top() - 1;
            st.push(i);
        }    
        while(!st.empty()) st.pop();    

        int answer = INT_MIN;
        for(int i = 0;i < n;i++) {
            answer = max(answer,(((right[i] - left[i] + 1) * heights[i])));
        }
        return answer;
    }

    vector<vector<int>> intMatrix(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> answer(n,vector<int>(m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(matrix[i][j] == '1') answer[i][j] = 1;
            }
        }
        return answer;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat = intMatrix(matrix);
        int answer = INT_MIN;
        vector<int>heights = mat[0];
        answer = max(answer,largestRectangleArea(heights));

        for(int i = 1;i < mat.size();i++) {
            for(int j = 0;j < mat[0].size();j++) {
                if(mat[i][j] == 1) {
                    heights[j] = heights[j] + 1;
                }
                else heights[j] = 0;
            }
            answer = max(answer,largestRectangleArea(heights));
        }
        return answer;
    }
};