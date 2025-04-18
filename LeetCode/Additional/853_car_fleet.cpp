class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        for(int i = 0;i < speed.size();i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<double>nums;
        for(int i = 0;i < v.size();i++) {
            double temp = (double)(target - v[i].first) / v[i].second * 1.0;
            nums.push_back(temp);
        }
        for(auto it : nums) cout << it << " ";
        
        double maxi = 0; int ans = 0;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                ans++;
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>> cars(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];  
        }
        sort(cars.begin(), cars.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        });

        stack<float> st;
        for (int i = 0; i < n; i++) {
            float time = (float)(target - cars[i][0]) / cars[i][1];
            while (st.empty() || st.top() < time) {
                st.push(time);
            }
        }
        return st.size();
    }
};
*/
