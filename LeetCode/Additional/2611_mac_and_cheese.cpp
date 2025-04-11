class Solution {
public:
    int miceAndCheese(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<pair<int,int>>pq;
        int sum = 0;
        for(int i = 0;i < n;i++) {
            pq.push({nums1[i] - nums2[i], i});
            sum += nums2[i];
        }

        vector<int>visited(n,0);
        int ans = 0;
        int count = 0;

        while(!pq.empty()) {
            if(count == k) break;

            int num = pq.top().first;
            int index = pq.top().second;

            pq.pop();

            ans += nums1[index];
            sum -= nums2[index];
            count++;
        }
        return ans + sum;
    }
};

/*class Solution {
public:
    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
       priority_queue<int>pq;
        long long int ans=0;
        for(int i=0;i<r1.size();i++){
           pq.push(r1[i]-r2[i]);
            ans+=r2[i];
        }
        while(k!=0){
          ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};*/
