#define ll long long
class Solution {
public:
    void print(vector<ll>v) {
        for(auto it : v) cout << it << " ";
        cout << endl;
    }

    vector<ll>nse_(vector<int>&maxHeights) {
        ll n = maxHeights.size();
        vector<ll>answer(n);
        answer[n - 1] = n;
        stack<ll>st;
        st.push(n - 1);
        for(ll i = n - 2;i >= 0;i--) {
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i]) {
                st.pop();
            }
            if(st.empty()) {
                answer[i] = n;
            }
            else answer[i] = st.top();
            st.push(i);
        }
        return answer;
    }

    vector<ll>pse_(vector<int>&maxHeights) {
        ll n = maxHeights.size();
        vector<ll>answer(n);
        answer[0] = -1;
        stack<ll>st;
        st.push(0);
        for(ll i = 1;i < n;i++) {
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i]) {
                st.pop();
            }
            if(st.empty()) {
                answer[i] = -1;
            }
            else answer[i] = st.top();
            st.push(i);
        }
        return answer;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<ll>nse = nse_(maxHeights);
        // print(nse);
        vector<ll>pse = pse_(maxHeights);
        // print(pse);
        ll n = maxHeights.size();
        vector<ll>left(n,-1); vector<ll>right(n,-1);
        left[0] = maxHeights[0];
        for(ll i = 1;i < n;i++) {
            ll j = pse[i];
            ll temp = (i - j) * maxHeights[i];
            if(j != -1) temp += left[j];

            left[i] = temp;
        }
        // print(left);

        right[n - 1] = maxHeights[n - 1];
        for(ll i = n - 2;i >= 0;i--) {
            ll j = nse[i];
            ll temp = (j - i) * maxHeights[i];
            if(j != n) temp += right[j];

            right[i] = temp;
        }

        // print(right);

        vector<ll>answer; ll maxi = -1ll;
        for(ll i = 0;i < n;i++) {
            ll temp = left[i] + right[i] - maxHeights[i];
            maxi = max(maxi, temp);
            answer.push_back(temp);
        }
        // print(answer);
        return maxi;
    }
};
