
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums) mp[it]++;
        priority_queue<int>pq;
        for(auto it:mp) pq.push(it.second);

        while(pq.size() >= 2) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            num1--;
            num2--;
            if(num1 > 0) pq.push(num1);
            if(num2 > 0) pq.push(num2); 
        }

        return pq.size() ? pq.top() : 0;
    }
};
